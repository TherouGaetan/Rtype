//
// Created by Gaëtan Therou on 18-01-19.
//

#include "Exception.hpp"

namespace RType {

    Exception::Exception(const std::string &pTitle, const std::string &pMsg)
            : runtime_error(pTitle + ": " + pMsg)
    {

    }

    const char *Exception::what() const throw() {
        return mMessage.c_str();
    }
}