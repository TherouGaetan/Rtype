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
        AWidget(const sf::Vector2f &pDimension);
        AWidget(const sf::Vector2f &pDimension, const sf::Vector2f &pPosition);
        virtual ~AWidget();

    public:
        void        draw(sf::RenderTarget &pTarget, sf::RenderStates pStates) const override = 0;
        void        update(sf::Event &pEvent, sf::RenderWindow &pWin, sf::Time &pTimeSinceLastFrame) override = 0;
        void        manageEvent(sf::Event &pEvent, sf::RenderWindow &pWin) override = 0;

    public:
        const sf::Vector2f  &getDimension() const;
        const sf::Vector2f  &getPosition() const;
        const sf::Color     &getBackgroundColor() const;

    public:
        virtual void    setDimension(const sf::Vector2f &pDimension);
        virtual void    setDimension(unsigned int pWidth, unsigned int pHeight);
        virtual void    setPosition(const sf::Vector2f &pPosition);
        virtual void    setBackgroundColor(const sf::Color &pColor);

    protected:
        sf::Vector2f    mDimension;
        sf::Vector2f    mPosition;
        sf::Color       mBackgroundColor;
    };

}


#endif //RTYPE_AWIDGET_HPP
