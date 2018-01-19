//
// Created by Gaëtan Therou on 18-01-19.
//

#include "AWidget.hpp"

namespace View {

    AWidget::AWidget()
            : AWidget(sf::Vector2u(100, 10))
    {
    }

    AWidget::AWidget(const sf::Vector2u &pDimension)
            : AWidget(pDimension, sf::Vector2u(0, 0))
    {

    }

    AWidget::AWidget(const sf::Vector2u &pDimension, const sf::Vector2u &pPosition)
            : mDimension(pDimension), mPosition(pPosition), mBackgroundColor(sf::Color::Black)
    {

    }

    AWidget::~AWidget() {

    }

    const sf::Vector2u &AWidget::getDimension() const {
        return mDimension;
    }

    const sf::Vector2u &AWidget::getPosition() const {
        return mPosition;
    }

    const sf::Color &AWidget::getBackgroundColor() const {
        return mBackgroundColor;
    }

    void AWidget::setDimension(const sf::Vector2u &pDimension) {
        mDimension = pDimension;
    }

    void AWidget::setDimension(unsigned int pWidth, unsigned int pHeight) {
        mDimension = sf::Vector2u(pWidth, pHeight);
    }

    void AWidget::setPosition(const sf::Vector2u &pPosition) {
        mPosition = pPosition;
    }

    void AWidget::setBackgroundColor(const sf::Color &pColor) {
        mBackgroundColor = pColor;
    }

}