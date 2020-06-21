#pragma once


#include "impl/config.h"
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <experimental/coroutine>
#include <boost/asio/ssl.hpp>
#include <boost/beast/ssl.hpp>
#include <boost/asio/awaitable.hpp>
#include <boost/asio/use_awaitable.hpp>
#include <boost/beast/core/tcp_stream.hpp>
#include <boost/beast/core/buffers_to_string.hpp>


#include "url.h"


using boost::asio::awaitable;
using boost::asio::use_awaitable;
namespace beast = boost::beast;
namespace net = boost::asio;
namespace ssl = boost::asio::ssl;
namespace http = beast::http;
using tcp = boost::asio::ip::tcp;

namespace boost::beast::addons::load::https {
    template<typename Executor>
    inline awaitable<std::string> get(const url &ref, int version, beast::ssl_stream<beast::tcp_stream> &stream,
            asio::use_awaitable_t<Executor> aw);

    template<typename Executor>
    inline awaitable<std::string> get(net::io_context &ioc, const url &ref, int version, ssl::context &ctx,
            asio::use_awaitable_t<Executor> aw);

    template<typename Executor>
    inline awaitable<std::string> get(net::io_context &ioc, const url &ref, asio::use_awaitable_t<Executor> aw);
}


#include "impl/https_request.ipp"

//#endif