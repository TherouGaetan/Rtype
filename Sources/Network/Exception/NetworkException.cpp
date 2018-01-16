//
// Created by Gaëtan Therou on 18-01-13.
//

#include "NetworkException.hpp"

namespace Network {
    NetworkException::NetworkException(const std::string &pMsg)
            : runtime_error(pMsg), mMessage(pMsg) {
        Logger::getInstance().logLine("NetworkException : " + mMessage + ".");
    }

    const char *NetworkException::what() const throw() {
        return mMessage.c_str();
    }

    NetworkException::NetworkException(const NetworkException &pException)
            : runtime_error(pException.mMessage), mMessage(pException.mMessage) {
    }

    NetworkException &NetworkException::operator=(const NetworkException &pException) {
        mMessage = pException.mMessage;
        return *this;
    }
}