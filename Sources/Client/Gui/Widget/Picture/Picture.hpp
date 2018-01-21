//
// Created by Gaëtan Therou on 18-01-20.
//

#ifndef RTYPE_PICTURE_HPP
#define RTYPE_PICTURE_HPP

#include "Client/Gui/Widget/APicture.hpp"

namespace View {
    namespace Widget {

        class Picture : public APicture {
        public:
            Picture(const sf::Texture &pTexture, const sf::Vector2f &pDimension);
            Picture(const sf::Texture &pTexture, const sf::Vector2f &pDimension, const sf::Vector2f &pPosition);
            virtual ~Picture();

        public:
            void draw(sf::RenderTarget &pTarget, sf::RenderStates pStates) const override;

            void update(sf::Event &pEvent, sf::RenderWindow &pWin, sf::Time &pTimeSinceLastFrame) override;

            void manageEvent(sf::Event &pEvent, sf::RenderWindow &pWin) override;
        };

    }
}


#endif //RTYPE_PICTURE_HPP
