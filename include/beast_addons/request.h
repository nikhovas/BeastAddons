#pragma once


#include "impl/config.h"
#include "http_request.h"
#include "https_request.h"


namespace boost::beast::addons::load {
    template<typename Executor>
    inline asio::awaitable<std::string> get(asio::io_context &executor, const url &url, asio::use_awaitable_t<Executor>);

    template<typename Executor>
    inline asio::awaitable<std::string> get(asio::io_context &executor, const std::string &ref, asio::use_awaitable_t<Executor>);
}


#include "impl/request.ipp"