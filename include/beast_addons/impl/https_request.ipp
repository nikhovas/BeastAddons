#pragma once


namespace boost::beast::addons::load::https {

    namespace detail {
        void load_root_certificates(ssl::context& ctx, boost::system::error_code& ec) {
            std::string const cert =
                    "-----BEGIN CERTIFICATE-----\n"
                    "MIIDrzCCApegAwIBAgIQCDvgVpBCRrGhdWrJWZHHSjANBgkqhkiG9w0BAQUFADBh\n"
                    "MQswCQYDVQQGEwJVUzEVMBMGA1UEChMMRGlnaUNlcnQgSW5jMRkwFwYDVQQLExB3\n"
                    "d3cuZGlnaWNlcnQuY29tMSAwHgYDVQQDExdEaWdpQ2VydCBHbG9iYWwgUm9vdCBD\n"
                    "QTAeFw0wNjExMTAwMDAwMDBaFw0zMTExMTAwMDAwMDBaMGExCzAJBgNVBAYTAlVT\n"
                    "MRUwEwYDVQQKEwxEaWdpQ2VydCBJbmMxGTAXBgNVBAsTEHd3dy5kaWdpY2VydC5j\n"
                    "b20xIDAeBgNVBAMTF0RpZ2lDZXJ0IEdsb2JhbCBSb290IENBMIIBIjANBgkqhkiG\n"
                    "9w0BAQEFAAOCAQ8AMIIBCgKCAQEA4jvhEXLeqKTTo1eqUKKPC3eQyaKl7hLOllsB\n"
                    "CSDMAZOnTjC3U/dDxGkAV53ijSLdhwZAAIEJzs4bg7/fzTtxRuLWZscFs3YnFo97\n"
                    "nh6Vfe63SKMI2tavegw5BmV/Sl0fvBf4q77uKNd0f3p4mVmFaG5cIzJLv07A6Fpt\n"
                    "43C/dxC//AH2hdmoRBBYMql1GNXRor5H4idq9Joz+EkIYIvUX7Q6hL+hqkpMfT7P\n"
                    "T19sdl6gSzeRntwi5m3OFBqOasv+zbMUZBfHWymeMr/y7vrTC0LUq7dBMtoM1O/4\n"
                    "gdW7jVg/tRvoSSiicNoxBN33shbyTApOB6jtSj1etX+jkMOvJwIDAQABo2MwYTAO\n"
                    "BgNVHQ8BAf8EBAMCAYYwDwYDVR0TAQH/BAUwAwEB/zAdBgNVHQ4EFgQUA95QNVbR\n"
                    "TLtm8KPiGxvDl7I90VUwHwYDVR0jBBgwFoAUA95QNVbRTLtm8KPiGxvDl7I90VUw\n"
                    "DQYJKoZIhvcNAQEFBQADggEBAMucN6pIExIK+t1EnE9SsPTfrgT1eXkIoyQY/Esr\n"
                    "hMAtudXH/vTBH1jLuG2cenTnmCmrEbXjcKChzUyImZOMkXDiqw8cvpOp/2PV5Adg\n"
                    "06O/nVsJ8dWO41P0jmP6P6fbtGbfYmbW0W5BjfIttep3Sp+dWOIrWcBAI+0tKIJF\n"
                    "PnlUkiaY4IBIqDfv8NZ5YBberOgOzW6sRBc4L0na4UU+Krk2U886UAb3LujEV0ls\n"
                    "YSEY1QSteDwsOoBrp+uvFRTp2InBuThs4pFsiv9kuXclVzDAGySj4dzp30d8tbQk\n"
                    "CAUw7C29C79Fv1C5qfPrmAESrciIxpg0X40KPMbp1ZWVbd4=\n"
                    "-----END CERTIFICATE-----\n"

                    "-----BEGIN CERTIFICATE-----\n"
                    "MIIDaDCCAlCgAwIBAgIJAO8vBu8i8exWMA0GCSqGSIb3DQEBCwUAMEkxCzAJBgNV\n"
                    "BAYTAlVTMQswCQYDVQQIDAJDQTEtMCsGA1UEBwwkTG9zIEFuZ2VsZXNPPUJlYXN0\n"
                    "Q049d3d3LmV4YW1wbGUuY29tMB4XDTE3MDUwMzE4MzkxMloXDTQ0MDkxODE4Mzkx\n"
                    "MlowSTELMAkGA1UEBhMCVVMxCzAJBgNVBAgMAkNBMS0wKwYDVQQHDCRMb3MgQW5n\n"
                    "ZWxlc089QmVhc3RDTj13d3cuZXhhbXBsZS5jb20wggEiMA0GCSqGSIb3DQEBAQUA\n"
                    "A4IBDwAwggEKAoIBAQDJ7BRKFO8fqmsEXw8v9YOVXyrQVsVbjSSGEs4Vzs4cJgcF\n"
                    "xqGitbnLIrOgiJpRAPLy5MNcAXE1strVGfdEf7xMYSZ/4wOrxUyVw/Ltgsft8m7b\n"
                    "Fu8TsCzO6XrxpnVtWk506YZ7ToTa5UjHfBi2+pWTxbpN12UhiZNUcrRsqTFW+6fO\n"
                    "9d7xm5wlaZG8cMdg0cO1bhkz45JSl3wWKIES7t3EfKePZbNlQ5hPy7Pd5JTmdGBp\n"
                    "yY8anC8u4LPbmgW0/U31PH0rRVfGcBbZsAoQw5Tc5dnb6N2GEIbq3ehSfdDHGnrv\n"
                    "enu2tOK9Qx6GEzXh3sekZkxcgh+NlIxCNxu//Dk9AgMBAAGjUzBRMB0GA1UdDgQW\n"
                    "BBTZh0N9Ne1OD7GBGJYz4PNESHuXezAfBgNVHSMEGDAWgBTZh0N9Ne1OD7GBGJYz\n"
                    "4PNESHuXezAPBgNVHRMBAf8EBTADAQH/MA0GCSqGSIb3DQEBCwUAA4IBAQCmTJVT\n"
                    "LH5Cru1vXtzb3N9dyolcVH82xFVwPewArchgq+CEkajOU9bnzCqvhM4CryBb4cUs\n"
                    "gqXWp85hAh55uBOqXb2yyESEleMCJEiVTwm/m26FdONvEGptsiCmF5Gxi0YRtn8N\n"
                    "V+KhrQaAyLrLdPYI7TrwAOisq2I1cD0mt+xgwuv/654Rl3IhOMx+fKWKJ9qLAiaE\n"
                    "fQyshjlPP9mYVxWOxqctUdQ8UnsUKKGEUcVrA08i1OAnVKlPFjKBvk+r7jpsTPcr\n"
                    "9pWXTO9JrYMML7d+XRSZA1n3856OqZDX4403+9FnXCvfcLZLLKTBvwwFgEFGpzjK\n"
                    "UEVbkhd5qstF6qWK\n"
                    "-----END CERTIFICATE-----\n";
            ;

            ctx.add_certificate_authority(boost::asio::buffer(cert.data(), cert.size()), ec);

            if(ec) {
                return;
            }
        }

    } // detail



    void load_root_certificates(ssl::context& ctx, boost::system::error_code& ec) {
        detail::load_root_certificates(ctx, ec);
    }



    void load_root_certificates(ssl::context& ctx) {
        boost::system::error_code ec;
        detail::load_root_certificates(ctx, ec);
        if(ec)
            throw boost::system::system_error{ec};
    }



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