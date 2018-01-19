//
// Created by Gaëtan Therou on 18-01-19.
//

#ifndef RTYPE_AWIDGET_HPP
#define RTYPE_AWIDGET_HPP

#include "Client/Gui/IObject.hpp"

namespace View {

    class AWidget: public IObject {
    public:
        AWidget();
        AWidget(const sf::Vector2u &pDimension);
        AWidget(const sf::Vector2u &pDimension, const sf::Vector2u &pPosition);
        virtual ~AWidget();

    public:
        void        draw(sf::RenderTarget &pTarget, sf::RenderStates pStates) const override = 0;
        void        update(sf::Event &pEvent, sf::RenderWindow &pWin, sf::Time &pTimeSinceLastFrame) override = 0;
        void        manageEvent(sf::Event &pEvent, sf::RenderWindow &pWin) override = 0;

    public:
        const sf::Vector2u  &getDimension() const;
        const sf::Vector2u  &getPosition() const;
        const sf::Color     &getBackgroundColor() const;

    public:
        void    setDimension(const sf::Vector2u &pDimension);
        void    setDimension(unsigned int pWidth, unsigned int pHeight);
        void    setPosition(const sf::Vector2u &pPosition);
        void    setBackgroundColor(const sf::Color &pColor);

    protected:
        sf::Vector2u    mDimension;
        sf::Vector2u    mPosition;
        sf::Color       mBackgroundColor;
    };

}


#endif //RTYPE_AWIDGET_HPP
