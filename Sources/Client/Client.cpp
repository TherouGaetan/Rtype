//
// Created by Gaëtan Therou on 18-01-18.
//

#include <iostream>
#include "Client.hpp"
#include "Client/Gui/ViewManager.hpp"

namespace RType {

    Client::Client()
            : mWindow(sf::VideoMode(1920, 1080), "Client R-Type", sf::Style::Default)
    {
        mWindow.setFramerateLimit(60);
        ::View::ViewManager::getInstance().setActiveView("Authentication");
    }

    void Client::initializeRessource() {

    }

    void Client::runGame() {
        while (mWindow.isOpen()) {
            if (::View::ViewManager::getInstance().needChange())
                ::View::ViewManager::getInstance().changeView();
            while (mWindow.pollEvent(mEvent))
            {
                if (mEvent.type == sf::Event::Closed)
                    mWindow.close();
                ::View::ViewManager::getInstance().manageEvent(mEvent, mWindow);
            }

            mWindow.clear();
            mWindow.draw(*::View::ViewManager::getInstance().getActiveView());
            mWindow.display();
        }
    }
}