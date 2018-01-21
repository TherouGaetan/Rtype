//
// Created by Gaëtan Therou on 18-01-18.
//

#ifndef RTYPE_CLIENT_HPP
#define RTYPE_CLIENT_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "Gui/RessourcesManager.hpp"

namespace RType {

    class Client {
    public:
        Client();
        ~Client() = default;;

    public:
        void    runGame();

    private:
        void    initializeRessource();

    private:
        sf::RenderWindow    mWindow;
        sf::Event           mEvent;
        sf::Clock           mClock;
        sf::Time            mTimeSinceLastFrame;
    };

}


#endif //RTYPE_CLIENT_HPP
