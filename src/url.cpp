#include "beast_addons/url.h"


namespace boost::beast::addons {
    std::ostream &operator<<(std::ostream &stream, const boost::beast::addons::url &url) {
        stream << static_cast<std::string>(url);
        return stream;
    }
}