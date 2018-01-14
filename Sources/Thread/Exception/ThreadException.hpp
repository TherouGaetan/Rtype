//
// Created by Gaëtan Therou on 18-01-13.
//

#ifndef RTYPE_THREADEXCEPTION_HPP
#define RTYPE_THREADEXCEPTION_HPP

#include <stdexcept>
#include <string>

namespace Thread {
    class ThreadException :public std::runtime_error {
    public:
        explicit ThreadException(const std::string &pMessage);
        virtual ~ThreadException() throw() {};

        const char *what() const throw() override ;

    private:
        std::string     mMessage;
    };
}

#endif //RTYPE_THREADEXCEPTION_HPP
