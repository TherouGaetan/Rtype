//
// Created by Gaëtan Therou on 18-01-19.
//

#include <iostream>
#include "RessourcesManager.hpp"

namespace View {

    RessourcesManager *RessourcesManager::mInstance = nullptr;

    RessourcesManager::RessourcesManager() {
        loadFileFromPath("./Assets/img", &RessourcesManager::addTexture);
        loadFileFromPath("./Assets/police", &RessourcesManager::addFont);
        loadFileFromPath("./Assets/sound", &RessourcesManager::addSound);
    }

    RessourcesManager::~RessourcesManager() {

    }

    RessourcesManager *RessourcesManager::getInstance() {
        if (mInstance == nullptr) {
            mInstance = new RessourcesManager();
        }
        return mInstance;
    }

    const sf::Texture &RessourcesManager::getTexture(const std::string &pName) const {
        return mTextures.at(pName);
    }

    const sf::Font &RessourcesManager::getFont(const std::string &pName) const {
        return mFonts.at(pName);
    }

    const sf::SoundBuffer &RessourcesManager::getSound(const std::string &pName) const {
        return mSounds.at(pName);
    }

    void RessourcesManager::loadFileFromPath(const std::string &pPath, RessourcesManager::tAddFile pFunc) {
        DIR *dir = opendir(pPath.c_str());
        struct dirent *dirent = readdir(dir);

        Network::Logger::getInstance().logLine("Loading ressources from " + pPath);

        do {
            std::string entry(dirent->d_name);
            if (dirent->d_type == DT_DIR) {
                if (entry != "." && entry != "..") {
                    loadFileFromPath(pPath + "/" + entry, pFunc);
                }
            } else {
                (this->*pFunc)(pPath + "/" + entry, entry.substr(0, entry.length() - 4));
            }
        } while ((dirent = readdir(dir)));
    }

    void RessourcesManager::addTexture(const std::string &pPath, const std::string &pName) {
        sf::Texture add;
        if (!add.loadFromFile(pPath))
            throw RType::View::GuiException("Resources: Error while loading texture \"" + pPath + "\"");
        Network::Logger::getInstance().logLine("Adding texture " + pName + " from \"" + pPath + "\"");
        mTextures[pName] = add;
    }

    void RessourcesManager::addFont(const std::string &pPath, const std::string &pName) {
        sf::Font add;
        if (!add.loadFromFile(pPath))
            throw RType::View::GuiException("Resources: Error while loading font \"" + pPath + "\"");
        Network::Logger::getInstance().logLine("Adding font " + pName + " from \"" + pPath + "\"");
        mFonts[pName] = add;
    }

    void RessourcesManager::addSound(const std::string &pPath, const std::string &pName) {
        sf::SoundBuffer add;
        if (!add.loadFromFile(pPath))
            throw RType::View::GuiException("Resources: Error while loading sound \"" + pPath + "\"");
        Network::Logger::getInstance().logLine("Adding sound " + pName + " from \"" + pPath + "\"");
        mSounds[pName] = add;
    }
}
