//
// Created by Gaëtan Therou on 18-01-19.
//

#ifndef RTYPE_EXCEPTION_HPP
#define RTYPE_EXCEPTION_HPP

#include <string>

namespace RType {

    class Exception : public std::runtime_error {
    public:
        explicit Exception(const std::string &pTitle, const std::string &pMsg);
        ~Exception() override {};

    public:
        const char *what() const throw() override ;

    private:
        std::string mMessage;
    };

}

#endif //RTYPE_EXCEPTION_HPP
