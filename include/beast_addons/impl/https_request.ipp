#pragma once


namespace boost::beast::addons::load::https {

    template<typename Executor>
    awaitable<std::string> get(net::io_context& ioc, const url& ref, int version, ssl::context& ctx,
            asio::use_awaitable_t<Executor> aw) {
        namespace bhttp = boost::beast::http;

        tcp::resolver resolver(ioc);
        beast::ssl_stream<beast::tcp_stream> stream(ioc, ctx);

        if (!SSL_set_tlsext_host_name(stream.native_handle(), ref.host.c_str())) {
            co_return "";
        }

        auto const results = co_await resolver.async_resolve(ref.host, "443", use_awaitable);
        beast::get_lowest_layer(stream).expires_after(std::chrono::seconds(30));
        co_await get_lowest_layer(stream).async_connect(results, use_awaitable);
        beast::get_lowest_layer(stream).expires_after(std::chrono::seconds(30));
        co_await stream.async_handshake(ssl::stream_base::client, use_awaitable);

        int result_code;

        bhttp::response<bhttp::dynamic_body> res;

        do {
            bhttp::request<bhttp::string_body> req{bhttp::verb::get, ref.target, version};
            req.set(bhttp::field::host, ref.host);
            req.set(bhttp::field::user_agent, "Mozilla/5.0 (iPhone; CPU iPhone OS 10_3_1 like Mac OS X) AppleWebKit/603.1.30 (KHTML, like Gecko) Version/10.0 Mobile/14E304 Safari/602.1");


            beast::get_lowest_layer(stream).expires_after(std::chrono::seconds(30));

            co_await bhttp::async_write(stream, req, use_awaitable);

            beast::flat_buffer b;

            co_await bhttp::async_read(stream, b, res, use_awaitable);

            result_code = res.result_int();
        } while (result_code == 503);


        beast::get_lowest_layer(stream).expires_after(std::chrono::seconds(30));

        try {
            co_await stream.async_shutdown(use_awaitable);
        } catch (...) {
        }

        co_return boost::beast::buffers_to_string(res.body().data());
    }



    template<typename Executor>
    awaitable<std::string> get(const url &ref, int version, beast::ssl_stream<beast::tcp_stream> &stream,
                                            asio::use_awaitable_t<Executor> aw) {
        namespace bhttp = boost::beast::http;

        bhttp::request<bhttp::string_body> req{bhttp::verb::get, ref.target, version};
        req.set(bhttp::field::host, ref.host);

        beast::get_lowest_layer(stream).expires_after(std::chrono::seconds(30));

        co_await bhttp::async_write(stream, req, use_awaitable);

        beast::flat_buffer b;
        bhttp::response<bhttp::dynamic_body> res;

        co_await bhttp::async_read(stream, b, res, use_awaitable);

        beast::get_lowest_layer(stream).expires_after(std::chrono::seconds(30));

        co_return boost::beast::buffers_to_string(res.body().data());
    }



    template<typename Executor>
    awaitable<std::string> get(net::io_context &ioc, const url &ref, asio::use_awaitable_t<Executor> aw) {
        ssl::context ctx{ssl::context::tlsv12_client};
        load_root_certificates(ctx);
        ctx.set_verify_mode(ssl::verify_none);
        co_return co_await get(ioc, ref, 11, ctx, aw);
    }
}