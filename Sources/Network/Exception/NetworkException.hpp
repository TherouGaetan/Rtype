#pragma once

#include <iostream>
#include <exception>
#include <stdexcept>

#include "../Logger/Logger.hpp"

namespace Network {
    class NetworkException : public std::runtime_error {
    public:
        NetworkException(const std::string &pMsg);

        virtual ~NetworkException() throw() {}

        const char *what() const throw() override;

    private:
        std::string mMessage;
    };
}
