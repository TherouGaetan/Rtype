//
// Created by Gaëtan Therou on 18-01-18.
//

#ifndef RTYPE_AVIEW_HPP
#define RTYPE_AVIEW_HPP

#include <map>
#include "Client/Gui/Widget/AWidget.hpp"
#include "Network/Socket/Packet.hpp"

namespace View {

    class AView: public AWidget {
    public:
        explicit AView();
        virtual ~AView();

    public:
        unsigned int    getAntiAliasing() const;

    public:
        void            setAntiAliasing(unsigned int pAntiAliasing);

    protected:
        virtual void    initView() = 0;

    public:
        virtual void    notifyRecievedNetwork(const Network::TSocket::Packet &pPackage);

    public:
        void        draw(sf::RenderTarget &pTarget, sf::RenderStates pStates) const override = 0;
        void        update(sf::Event &pEvent, sf::RenderWindow &pWin, sf::Time &pTimeSinceLastFrame) override = 0;
        void        manageEvent(sf::Event &pEvent, sf::RenderWindow &pWin) override = 0;

    protected:
        unsigned int        mAntiAliasing;
        std::multimap<unsigned int,
                AWidget *>  mWidget;
    };

}


#endif //RTYPE_AVIEW_HPP
