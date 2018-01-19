//
// Created by Gaëtan Therou on 18-01-19.
//

#ifndef RTYPE_GUIEXCEPTION_HPP
#define RTYPE_GUIEXCEPTION_HPP

#include <string>

#include "Client/Exception/Exception.hpp"

namespace RType {
    namespace View {

        class GuiException : public Exception {
        public:
            explicit GuiException(const std::string &pMsg);
        };

    }
}


#endif //RTYPE_GUIEXCEPTION_HPP
