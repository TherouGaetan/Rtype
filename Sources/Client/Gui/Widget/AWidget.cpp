//
// Created by Gaëtan Therou on 18-01-19.
//

#include "AWidget.hpp"

namespace View {

    AWidget::AWidget()
            : AWidget(sf::Vector2f(100, 100))
    {
    }

    AWidget::AWidget(const sf::Vector2f &pDimension)
            : AWidget(pDimension, sf::Vector2f(0, 0))
    {

    }

    AWidget::AWidget(const sf::Vector2f &pDimension, const sf::Vector2f &pPosition)
            : mDimension(pDimension), mPosition(pPosition), mBackgroundColor(sf::Color::Black)
    {

    }

    AWidget::~AWidget() {

    }

    const sf::Vector2f &AWidget::getDimension() const {
        return mDimension;
    }

    const sf::Vector2f &AWidget::getPosition() const {
        return mPosition;
    }

    const sf::Color &AWidget::getBackgroundColor() const {
        return mBackgroundColor;
    }

    void AWidget::setDimension(const sf::Vector2f &pDimension) {
        mDimension = pDimension;
    }

    void AWidget::setDimension(unsigned int pWidth, unsigned int pHeight) {
        mDimension = sf::Vector2f(pWidth, pHeight);
    }

    void AWidget::setPosition(const sf::Vector2f &pPosition) {
        mPosition = pPosition;
    }

    void AWidget::setBackgroundColor(const sf::Color &pColor) {
        mBackgroundColor = pColor;
    }

}