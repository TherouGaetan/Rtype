//
// Created by Gaëtan Therou on 18-01-18.
//

#ifndef RTYPE_VIEWMANAGER_HPP
#define RTYPE_VIEWMANAGER_HPP


#include <string>

#include "ViewFactory.hpp"
#include "Client/Exception/GuiException.hpp"

namespace View {

    class ViewManager {
    public:
        virtual ~ViewManager();

    public:
        static ViewManager  &getInstance();
        void                changeView();
        void                setActiveView(const std::string &pName);
        bool                needChange() const;

    private:
        explicit ViewManager();

    private:
        static ViewManager  mInstance;
        ViewFactory         mFactory;
        std::map<std::string, AView *>  mViews;
        AView               *mViewActive;
        AView               *mViewFutur;
    };

}


#endif //RTYPE_VIEWMANAGER_HPP
