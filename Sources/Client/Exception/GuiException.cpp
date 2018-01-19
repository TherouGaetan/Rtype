//
// Created by Gaëtan Therou on 18-01-19.
//

#include "GuiException.hpp"

namespace RType {
    namespace View {
        GuiException::GuiException(const std::string &pMsg)
                : Exception("GuiException", pMsg) {
        }
    }
}
