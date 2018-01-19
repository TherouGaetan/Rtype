//
// Created by Gaëtan Therou on 18-01-13.
//

#include "ThreadException.hpp"

namespace Thread {

    ThreadException::ThreadException(const std::string &pMessage)
            : runtime_error(pMessage), mMessage(pMessage)
    {
    }

    const char *ThreadException::what() const throw() {

        return mMessage.c_str();
    }

}
