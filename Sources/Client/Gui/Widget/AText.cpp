//
// Created by Gaëtan Therou on 18-01-20.
//

#include "AText.hpp"


namespace View {
    namespace Widget {

        AText::AText(const std::string &pText, const sf::Font &pFont)
                : AText(pText, pFont, sf::Vector2f(0, 0), sf::Color::Black, 24)
        {

        }

        AText::AText(const std::string &pText, const sf::Font &pFont, const sf::Vector2f &pPos)
                : AText(pText, pFont, pPos, sf::Color::Black, 24)
        {

        }

        AText::AText(const std::string &pText, const sf::Font &pFont, const sf::Vector2f &pPos, sf::Color pColor)
                : AText(pText, pFont, pPos, pColor, 24)
        {

        }

        AText::AText(const std::string &pText, const sf::Font &pFont, const sf::Vector2f &pPos, unsigned int pSize)
                : AText(pText, pFont, pPos, sf::Color::Black, pSize)
        {

        }

        AText::AText(const std::string &pText, const sf::Font &pFont, const sf::Vector2f &pPos, sf::Color pColor, unsigned int pSize)
                : AWidget()
        {
            mPosition = pPos;
            mText.setPosition(pPos);
            mText.setFont(pFont);
            mText.setCharacterSize(pSize);
            mText.setFillColor(pColor);
            mText.setString(pText);
        }

        AText::~AText() {

        }

        const std::string &AText::getText() const {
            return mText.getString();
        }

        void AText::setText(const std::string &pText) {
            mText.setString(pText);
        }

        void AText::setColorText(const sf::Color &pColor) {
            mText.setFillColor(pColor);
        }

        void AText::setSize(unsigned int pSize) {
            mText.setCharacterSize(pSize);
        }

        void AText::setPosition(const sf::Vector2f &pPosition) {
            AWidget::setPosition(pPosition);
            mText.setPosition(mPosition);
        }

        void AText::setBackgroundColor(const sf::Color &pColor) {
            AWidget::setBackgroundColor(pColor);
            mText.setOutlineColor(mBackgroundColor);
        }

    }
}