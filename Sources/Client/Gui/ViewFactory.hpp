//
// Created by Gaëtan Therou on 18-01-18.
//

#ifndef RTYPE_VIEWFACTORY_HPP
#define RTYPE_VIEWFACTORY_HPP

#include <string>
#include <map>

#include "Client/Gui/View/AView.hpp"
#include "Client/Gui/Scene/AuthenticationScene.hpp"

namespace View {

    class ViewFactory {
    public:
        explicit ViewFactory();
        virtual ~ViewFactory() {};

    public:
        AView   *makeView(const std::string &pNameView);

    private:
        typedef AView *(ViewFactory::*createView)();
        AView   *makeAuthenticate();

    private:
        std::map<std::string, createView> mViewsList;
    };

}


#endif //RTYPE_VIEWFACTORY_HPP
