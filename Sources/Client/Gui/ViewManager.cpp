//
// Created by Gaëtan Therou on 18-01-18.
//

#include "ViewManager.hpp"

namespace View {

    ViewManager ViewManager::mInstance = ViewManager();

    ViewManager::ViewManager() {
        mViewFutur = nullptr;
        mViewActive = nullptr;
    }

    ViewManager::~ViewManager() {
    }

    ViewManager &ViewManager::getInstance() {
        return mInstance;
    }

    void ViewManager::changeView() {
        mViewActive = mViewFutur;
        mViewFutur = nullptr;
    }

    void ViewManager::setActiveView(const std::string &pName) {
        if (mViews.find(pName) == mViews.end()) {
            AView *view = mFactory.makeView(pName);
            if (view == nullptr)
                throw RType::View::GuiException("View not found");
            mViews[pName] = view;
        }
        mViewFutur = mViews[pName];
    }

    bool ViewManager::needChange() const {
        return mViewFutur != nullptr;
    }

    void ViewManager::manageEvent(sf::Event &pEvent, sf::RenderWindow &pWin) {
        mViewActive->manageEvent(pEvent, pWin);
    }

    AView *ViewManager::getActiveView() const {
        return mViewActive;
    }
}