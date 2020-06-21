#pragma once


namespace boost::beast::addons::load {
    template<typename Executor>
    asio::awaitable<std::string> get(asio::io_context &executor, const url &url, asio::use_awaitable_t<Executor> aw) {
        co_return co_await (url.protocol == "https" ? https::get(executor, url, aw) : http::get(executor, url, aw));
    }

    template<typename Executor>
    asio::awaitable<std::string> get(asio::io_context &executor, const std::string &ref,
            asio::use_awaitable_t<Executor> aw) {
        co_return co_await get(executor, static_cast<url>(ref), aw);
    }
}