//
// Created by Gaëtan Therou on 18-01-19.
//

#include "AuthenticationScene.hpp"
#include "Client/Gui/RessourcesManager.hpp"
#include "Client/Gui/Widget/Picture/Picture.hpp"
#include "Client/Gui/Widget/Bouton/PushButton.hpp"

namespace View {

    AuthenticationScene::AuthenticationScene(unsigned int pWidth, unsigned int pHeight)
            : Widget::AView(sf::Vector2f(pWidth, pHeight))
    {
        initView();
    }

    AuthenticationScene::~AuthenticationScene() {

    }

    void AuthenticationScene::initView() {
        mWidget.insert(std::pair<unsigned int, AWidget *>(0, new Widget::Picture(
                RessourcesManager::getInstance()->getTexture("Connexion"), mDimension)));
        mWidget.insert(std::pair<unsigned int, AWidget *>(1, new Widget::PushButton("Quitter", sf::Vector2f(125, 25),
        RessourcesManager::getInstance()->getFont("Capture_it"))));
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