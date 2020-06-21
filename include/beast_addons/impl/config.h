#pragma once


#define BEASTADDONS


#ifdef BOOST_VERSION
    #define BEASTADDONS_NAMESPACE boost::beast::addons
#elif BEAST_API_VERSION
    #define BEASTADDONS_NAMESPACE beast::addons
#endif
