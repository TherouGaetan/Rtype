//
// Created by Gaëtan Therou on 18-01-20.
//

#include "AButton.hpp"


namespace View {
    namespace Widget {

        AButton::AButton(const std::string &pContent, const sf::Vector2f &pDimension, const sf::Font &pFont)
                : AButton(pContent, pDimension, pFont, sf::Vector2f(0, 0))
        {

        }

        AButton::AButton(const std::string &pContent, const sf::Vector2f &pDimension, const sf::Font &pFont,
                         const sf::Vector2f &pPos)
                : AWidget(pDimension, pPos), mLabel(pContent, pFont, pPos), mColorNormal(sf::Color(125,125,125)),
                  mColorClicked(mColorNormal), mColorHovered(sf::Color(100, 100, 100)), mShape(pDimension)
        {

        }

        AButton::~AButton() {

        }
    }
}