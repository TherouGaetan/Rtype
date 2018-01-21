//
// Created by Gaëtan Therou on 18-01-20.
//

#ifndef RTYPE_ATEXT_HPP
#define RTYPE_ATEXT_HPP

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

#include "AWidget.hpp"

namespace View {
    namespace Widget {

        class AText : public AWidget {
        public:
            AText(const std::string &pText, const sf::Font &pFont);
            AText(const std::string &pText, const sf::Font &pFont, const sf::Vector2f &pPos);
            AText(const std::string &pText, const sf::Font &pFont, const sf::Vector2f &pPos, sf::Color pColor);
            AText(const std::string &pText, const sf::Font &pFont, const sf::Vector2f &pPos, unsigned int pSize);
            AText(const std::string &pText, const sf::Font &pFont, const sf::Vector2f &pPos, sf::Color pColor, unsigned int pSize);
            virtual ~AText();

        public:
            const std::string   &getText() const;

        public:
            void    setText(const std::string &pText);
            void    setColorText(const sf::Color &pColor);
            void    setBackgroundColor(const sf::Color &pColor) override;
            void    setSize(unsigned int pSize);
            void    setPosition(const sf::Vector2f &pPosition) override;

        public:
            void draw(sf::RenderTarget &pTarget, sf::RenderStates pStates) const override = 0;
            void update(sf::Event &pEvent, sf::RenderWindow &pWin, sf::Time &pTimeSinceLastFrame) override = 0;
            void manageEvent(sf::Event &pEvent, sf::RenderWindow &pWin) override = 0;

        protected:
            sf::Text        mText;
        };

    }
}


#endif //RTYPE_ATEXT_HPP
