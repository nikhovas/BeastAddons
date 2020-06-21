#include "gtest/gtest.h"
#include "beast_addons.h"
#include <boost/asio/co_spawn.hpp>
#include <boost/asio/use_awaitable.hpp>
#include <boost/asio/awaitable.hpp>
#include <boost/asio/detached.hpp>
#include <string>


namespace addons = boost::beast::addons;


TEST(Download, Simple) {
    boost::asio::io_context executor;
    boost::asio::co_spawn(executor, [&]() -> boost::asio::awaitable<void> {
        std::string res = co_await addons::load::get(executor, "https://httpsiseasy.com/", boost::asio::use_awaitable);
        std::cout << res << std::endl;
        co_return;
    }, boost::asio::detached);

    executor.run();
}
