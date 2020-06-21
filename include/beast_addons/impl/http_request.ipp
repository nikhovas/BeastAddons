namespace boost::beast::addons::load::http {

    template<typename Executor>
    asio::awaitable<std::string> get(net::io_context &ioc, const url &url, int version,
            asio::use_awaitable_t<Executor> aw) {

        namespace bhttp = boost::beast::http;

        beast::error_code ec;
        tcp::resolver resolver(ioc);
        beast::tcp_stream stream(ioc);

        auto const results = co_await resolver.async_resolve(url.host, "80", aw);
        stream.expires_after(std::chrono::seconds(30));
        co_await stream.async_connect(results, asio::use_awaitable);

        bhttp::request<bhttp::string_body> req{bhttp::verb::get, url.target, version};
        req.set(bhttp::field::host, url.host);
        req.set(bhttp::field::user_agent, BOOST_BEAST_VERSION_STRING);
        stream.expires_after(std::chrono::seconds(30));
        co_await bhttp::async_write(stream, req, aw);

        beast::flat_buffer b;
        bhttp::response<bhttp::dynamic_body> res;
        co_await bhttp::async_read(stream, b, res, aw);

        stream.socket().shutdown(tcp::socket::shutdown_both, ec);
        co_return boost::beast::buffers_to_string(res.body().data());
    }

    template<typename Executor>
    asio::awaitable<std::string> get(asio::io_context &executor, const url &url, asio::use_awaitable_t<Executor> aw) {
        co_return co_await get(executor, url, 11, aw);
    }

}