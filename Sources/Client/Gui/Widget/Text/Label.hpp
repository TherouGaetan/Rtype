//
// Created by Gaëtan Therou on 18-01-20.
//

#ifndef RTYPE_LABEL_HPP
#define RTYPE_LABEL_HPP


#include "../AText.hpp"

namespace View {
    namespace Widget {

        class Label : public AText {
        public:
            Label(const std::string &pText, const sf::Font &pFont);
            Label(const std::string &pText, const sf::Font &pFont, const sf::Vector2f &pPos);
            Label(const std::string &pText, const sf::Font &pFont, const sf::Vector2f &pPos, sf::Color pColor);
            Label(const std::string &pText, const sf::Font &pFont, const sf::Vector2f &pPos, unsigned int pSize);
            Label(const std::string &pText, const sf::Font &pFont, const sf::Vector2f &pPos, sf::Color pColor, unsigned int pSize);
            virtual ~Label();

        public:
            void draw(sf::RenderTarget &pTarget, sf::RenderStates pStates) const override;
            void update(sf::Event &pEvent, sf::RenderWindow &pWin, sf::Time &pTimeSinceLastFrame) override;
            void manageEvent(sf::Event &pEvent, sf::RenderWindow &pWin) override;
        };

    }
}


#endif //RTYPE_LABEL_HPP
