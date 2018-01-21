//
// Created by Gaëtan Therou on 18-01-20.
//

#include "Picture.hpp"

namespace View {
    namespace Widget {

        Picture::Picture(const sf::Texture &pTexture, const sf::Vector2f &pDimension)
                : Picture(pTexture, pDimension, sf::Vector2f(0, 0))
        {

        }

        Picture::Picture(const sf::Texture &pTexture, const sf::Vector2f &pDimension, const sf::Vector2f &pPosition)
                : APicture(pTexture, pDimension, pPosition)
        {

        }

        Picture::~Picture() {

        }

        void Picture::draw(sf::RenderTarget &pTarget, sf::RenderStates pStates) const {
            pTarget.draw(mShape);
        }

        void Picture::update(sf::Event &pEvent, sf::RenderWindow &pWin, sf::Time &pTimeSinceLastFrame) {
        }

        void Picture::manageEvent(sf::Event &pEvent, sf::RenderWindow &pWin) {
        }

    }
}