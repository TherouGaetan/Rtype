//
// Created by Gaëtan Therou on 18-01-20.
//

#ifndef RTYPE_ABOUTON_HPP
#define RTYPE_ABOUTON_HPP


#include <SFML/Graphics/RectangleShape.hpp>

#include "AWidget.hpp"
#include "./Text/Label.hpp"

namespace View {
    namespace Widget {

        class AButton : public AWidget {
        public:
            AButton(const std::string &pContent, const sf::Vector2f &pDimension, const sf::Font &pFont);
            AButton(const std::string &pContent, const sf::Vector2f &pDimension, const sf::Font &pFont, const sf::Vector2f &pPos);
            virtual ~AButton();

        public:
            void draw(sf::RenderTarget &pTarget, sf::RenderStates pStates) const override = 0;
            void update(sf::Event &pEvent, sf::RenderWindow &pWin, sf::Time &pTimeSinceLastFrame) override = 0;
            void manageEvent(sf::Event &pEvent, sf::RenderWindow &pWin) override = 0;

        protected:
            Label               mLabel;
            // Radius ?
            sf::RectangleShape  mShape;
            sf::Color           mColorNormal;
            sf::Color           mColorClicked;
            sf::Color           mColorHovered;

            // border ? size, color
        };

    }
}


#endif //RTYPE_ABOUTON_HPP
