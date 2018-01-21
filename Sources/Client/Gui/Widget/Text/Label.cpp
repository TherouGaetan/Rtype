//
// Created by Gaëtan Therou on 18-01-20.
//

#include "Label.hpp"


namespace View {
    namespace Widget {

        Label::Label(const std::string &pText, const sf::Font &pFont)
                : AText(pText, pFont)
        {

        }

        Label::Label(const std::string &pText, const sf::Font &pFont, const sf::Vector2f &pPos)
                : AText(pText, pFont, pPos) {

        }

        Label::Label(const std::string &pText, const sf::Font &pFont, const sf::Vector2f &pPos, sf::Color pColor)
                : AText(pText, pFont, pPos, pColor) {

        }

        Label::Label(const std::string &pText, const sf::Font &pFont, const sf::Vector2f &pPos, unsigned int pSize)
                : AText(pText, pFont, pPos, pSize) {

        }

        Label::Label(const std::string &pText, const sf::Font &pFont, const sf::Vector2f &pPos, sf::Color pColor,
                     unsigned int pSize)
                : AText(pText, pFont, pPos, pColor, pSize) {

        }

        Label::~Label() {

        }

        void Label::draw(sf::RenderTarget &pTarget, sf::RenderStates pStates) const {
            pTarget.draw(mText);
        }

        void Label::update(sf::Event &pEvent, sf::RenderWindow &pWin, sf::Time &pTimeSinceLastFrame) {
        }

        void Label::manageEvent(sf::Event &pEvent, sf::RenderWindow &pWin) {
        }

    }
}