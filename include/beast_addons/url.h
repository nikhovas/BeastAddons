#pragma once


#include "impl/config.h"
#include <string>


namespace boost::beast::addons {
    class url {
    public:
        inline url() = default;

        inline url(const std::string& url) {
            set_from_string(url);
        }


        inline operator std::string() const {
            std::string result;

            if (protocol != "") {
                result += protocol + "://";
            }

            result += host;

            if (target != "") {
                result += "/" + target;
            }

            return result;
        }

        inline url& operator=(const std::string& url) {
            set_from_string(url);
            return *this;
        }

        std::string protocol;
        std::string host;
        std::string target;

    private:
        inline void set_from_string(const std::string& url) {
            size_t protocol_end_pos = url.find_first_of("://");
            std::string without_protocol = url.substr(protocol_end_pos + 3, url.size());
            size_t separator = without_protocol.find_first_of("/");
            protocol = url.substr(0, protocol_end_pos);
            host = without_protocol.substr(0, separator);
            target = without_protocol.substr(separator, without_protocol.size());
        }
    };

    std::ostream& operator<< (std::ostream& stream, const url& url);
}