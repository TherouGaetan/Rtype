//
// Created by Gaëtan Therou on 18-01-20.
//

#ifndef RTYPE_PUSHBUTTON_HPP
#define RTYPE_PUSHBUTTON_HPP


#include "Client/Gui/Widget/AButton.hpp"

namespace View {
    namespace Widget {

        class PushButton : public AButton{
        public:
            PushButton(const std::string &pContent, const sf::Vector2f &pDimension, const sf::Font &pFont);
            PushButton(const std::string &pContent, const sf::Vector2f &pDimension, const sf::Font &pFont, const sf::Vector2f &pPos);
            virtual ~PushButton();

        public:
            void draw(sf::RenderTarget &pTarget, sf::RenderStates pStates) const override;
            void update(sf::Event &pEvent, sf::RenderWindow &pWin, sf::Time &pTimeSinceLastFrame) override;
            void manageEvent(sf::Event &pEvent, sf::RenderWindow &pWin) override;

        };

    }
}


#endif //RTYPE_PUSHBUTTON_HPP
