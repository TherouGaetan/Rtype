//
// Created by Gaëtan Therou on 18-01-20.
//

#include "APicture.hpp"

namespace View {
    namespace Widget {

        APicture::APicture(const sf::Texture &pTexture, const sf::Vector2f &pDimension)
                : APicture(pTexture, pDimension, sf::Vector2f(0, 0)) {
        }

        APicture::APicture(const sf::Texture &pTexture, const sf::Vector2f &pDimension, const sf::Vector2f &pPosition)
                : AWidget(pDimension, pPosition), mTexture(pTexture) {
            mShape.setPosition(pPosition);
            mShape.setSize(pDimension);
            mShape.setTexture(&pTexture);
        }

        APicture::~APicture() {

        }

    }
}