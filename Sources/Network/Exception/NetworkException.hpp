#pragma once

#include <iostream>
#include <exception>
#include <stdexcept>

#include "../Logger/Logger.hpp"

namespace Network {
    class NetworkException : public std::runtime_error {
    public:
        explicit NetworkException(const std::string &pMsg);
        NetworkException(const NetworkException &pException);
        virtual ~NetworkException() throw() {}

    public:
        NetworkException &operator=(const NetworkException &pException);
        const char *what() const throw() override;

    private:
        std::string mMessage;
    };
}
