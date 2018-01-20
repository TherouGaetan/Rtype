//
// Created by Gaëtan Therou on 18-01-19.
//

#ifndef RTYPE_RESSOURCESMANAGER_HPP
#define RTYPE_RESSOURCESMANAGER_HPP

#include <map>
#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

#include <dirent.h>
#ifndef WIN32
#include <sys/types.h>
#endif

#include "Client/Exception/GuiException.hpp"
#include "Network/Logger/Logger.hpp"

namespace View {

    class RessourcesManager {
    public:
        virtual ~RessourcesManager();
        typedef void (View::RessourcesManager::*tAddFile)(const std::string &, const std::string &);

    private:
        RessourcesManager();

    private:
        void    loadFileFromPath(const std::string &pPath, tAddFile pFunc);
        void    addTexture(const std::string &pPath, const std::string &pName);
        void    addFont(const std::string &pPath, const std::string &pName);
        void    addSound(const std::string &pPath, const std::string &pName);

    public:
        static RessourcesManager    *getInstance();
        const sf::Texture           &getTexture(const std::string &pName) const;
        const sf::Font              &getFont(const std::string &pName) const;
        const sf::SoundBuffer       &getSound(const std::string &pName) const;

    private:
        static RessourcesManager                *mInstance;
        std::map<std::string, sf::Texture>      mTextures;
        std::map<std::string, sf::Font>         mFonts;
        std::map<std::string, sf::SoundBuffer>  mSounds;
    };

}


#endif //RTYPE_RESSOURCESMANAGER_HPP
