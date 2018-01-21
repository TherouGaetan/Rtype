//
// Created by Gaëtan Therou on 18-01-18.
//

#include "ViewFactory.hpp"

namespace View {

    ViewFactory::ViewFactory() {
        mViewsList["Authentication"] = &ViewFactory::makeAuthenticate;
    }

    Widget::AView *ViewFactory::makeView(const std::string &pNameView) {
        if (mViewsList.find(pNameView) != mViewsList.end())
            return (this->*mViewsList[pNameView])();
        return nullptr;
    }

    Widget::AView *ViewFactory::makeAuthenticate() {
        return new AuthenticationScene(1920, 1080);
    }
}
