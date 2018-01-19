//
// Created by Gaëtan Therou on 18-01-19.
//

#ifndef RTYPE_AUTHENTICATIONSCENE_HPP
#define RTYPE_AUTHENTICATIONSCENE_HPP

#include "Client/Gui/View/AView.hpp"

namespace View {

    class AuthenticationScene : public AView{
    public:
        explicit AuthenticationScene(unsigned int pWidth, unsigned int pHeight);
        virtual ~AuthenticationScene();

    protected:
        void    initView() override;

    public:
        void        draw(sf::RenderTarget &pTarget, sf::RenderStates pStates) const override;
        void        update(sf::Event &pEvent, sf::RenderWindow &pWin, sf::Time &pTimeSinceLastFrame) override;
        void        manageEvent(sf::Event &pEvent, sf::RenderWindow &pWin) override;
    };

}


#endif //RTYPE_AUTHENTICATIONSCENE_HPP
