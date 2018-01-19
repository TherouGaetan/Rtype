//
// Created by Gaëtan Therou on 18-01-19.
//

#ifndef RTYPE_IOBJECT_HPP
#define RTYPE_IOBJECT_HPP

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

namespace View {

    class IObject {
    public:
        virtual ~IObject() {};

    public:
        virtual void        draw(sf::RenderTarget &pTarget, sf::RenderStates pStates) const = 0;
        virtual void        update(sf::Event &pEvent, sf::RenderWindow &pWin, sf::Time &pTimeSinceLastFrame) = 0;
        virtual void        manageEvent(sf::Event &pEvent, sf::RenderWindow &pWin) = 0;
    };
}

#endif //RTYPE_IOBJECT_HPP
