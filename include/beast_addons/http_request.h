#pragma once


#include "impl/config.h"
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/awaitable.hpp>
#include <boost/asio/use_awaitable.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <string>
#include <experimental/coroutine>
#include <boost/beast/core.hpp>


#include "url.h"


namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
using tcp = boost::asio::ip::tcp;


namespace boost::beast::addons::load::http {
    template<typename Executor>
    inline asio::awaitable <std::string> get(const url &url, int version, net::io_context &ioc, asio::use_awaitable_t<Executor>);

    template<typename Executor>
    inline asio::awaitable<std::string> get(asio::io_context &executor, const url &url, asio::use_awaitable_t<Executor>);
}


#include "impl/http_request.ipp"