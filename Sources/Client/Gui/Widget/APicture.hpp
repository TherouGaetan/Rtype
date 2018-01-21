//
// Created by Gaëtan Therou on 18-01-20.
//

#ifndef RTYPE_AIMAGE_HPP
#define RTYPE_AIMAGE_HPP

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "AWidget.hpp"

namespace View {
    namespace Widget {

        class APicture : public AWidget {
        public:
            APicture(const sf::Texture &pTexture, const sf::Vector2f &pDimension);
            APicture(const sf::Texture &pTexture, const sf::Vector2f &pDimension, const sf::Vector2f &pPosition);
            virtual ~APicture();

        public:
            void draw(sf::RenderTarget &pTarget, sf::RenderStates pStates) const override = 0;
            void update(sf::Event &pEvent, sf::RenderWindow &pWin, sf::Time &pTimeSinceLastFrame) override = 0;
            void manageEvent(sf::Event &pEvent, sf::RenderWindow &pWin) override = 0;

        protected:
            sf::Texture mTexture;
            sf::RectangleShape mShape;
        };

    }
}


#endif //RTYPE_AIMAGE_HPP
