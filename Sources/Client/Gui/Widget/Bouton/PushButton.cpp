//
// Created by Gaëtan Therou on 18-01-20.
//

#include "PushButton.hpp"


namespace View {
    namespace Widget {

        PushButton::PushButton(const std::string &pContent, const sf::Vector2f &pDimension, const sf::Font &pFont)
                : AButton(pContent, pDimension, pFont) {

        }

        PushButton::PushButton(const std::string &pContent, const sf::Vector2f &pDimension, const sf::Font &pFont,
                               const sf::Vector2f &pPos) : AButton(pContent, pDimension, pFont, pPos) {

        }

        PushButton::~PushButton() {

        }

        void PushButton::draw(sf::RenderTarget &pTarget, sf::RenderStates pStates) const {
            pTarget.draw(mShape, pStates);
            pTarget.draw(mLabel, pStates);
        }

        void PushButton::update(sf::Event &pEvent, sf::RenderWindow &pWin, sf::Time &pTimeSinceLastFrame) {
            //AButton::update(pEvent, pWin, pTimeSinceLastFrame);
        }

        void PushButton::manageEvent(sf::Event &pEvent, sf::RenderWindow &pWin) {
            //AButton::manageEvent(pEvent, pWin);
        }
    }
}