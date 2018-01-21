//
// Created by Gaëtan Therou on 18-01-18.
//

#include "AView.hpp"

namespace View {
    namespace Widget {

        AView::AView()
                : AWidget()
        {

        }

        AView::AView(const sf::Vector2f &pDimension)
                : AWidget(pDimension)
        {

        }

        AView::~AView() {

        }

        void AView::notifyRecievedNetwork(const Network::TSocket::Packet &pPackage) {

        }

        unsigned int AView::getAntiAliasing() const {
            return mAntiAliasing;
        }

        void AView::setAntiAliasing(unsigned int pAntiAliasing) {
            mAntiAliasing = pAntiAliasing;
        }

    }
}