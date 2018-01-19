//
// Created by Gaëtan Therou on 18-01-19.
//

#include "AuthenticationScene.hpp"

namespace View {

    AuthenticationScene::AuthenticationScene(unsigned int pWidth, unsigned int pHeight) {

    }

    AuthenticationScene::~AuthenticationScene() {

    }

    void AuthenticationScene::initView() {

    }

    void AuthenticationScene::draw(sf::RenderTarget &pTarget, sf::RenderStates pStates) const {
        std::multimap<unsigned int, AWidget *>::const_iterator it = mWidget.begin();

        for (; it != mWidget.end(); ++it) {
            (*it).second->draw(pTarget, pStates);
        }
    }

    void AuthenticationScene::update(sf::Event &pEvent, sf::RenderWindow &pWin, sf::Time &pTimeSinceLastFrame) {
        std::multimap<unsigned int, AWidget *>::iterator it = mWidget.begin();

        for (; it != mWidget.end(); ++it) {
            (*it).second->update(pEvent, pWin, pTimeSinceLastFrame);
        }
    }

    void AuthenticationScene::manageEvent(sf::Event &pEvent, sf::RenderWindow &pWin) {
        std::multimap<unsigned int, AWidget *>::iterator it = mWidget.begin();

        for (; it != mWidget.end(); ++it) {
            (*it).second->manageEvent(pEvent, pWin);
        }
    }
}