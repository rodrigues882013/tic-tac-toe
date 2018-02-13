#pragma once


#include <memory>
#include <string>

#include <SFML/Graphics.hpp>

#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"

namespace game {

    struct GameData
    {
        StateMachine machine;
        sf::RenderWindow window;
        AssetManager assets;
        InputManager inputs;
    };

    typedef std::shared_ptr<GameData> GameDataRef;

    class Game
    {
    public:
        Game(int, int, std::string);
        ~Game();

    private:
        const float dt = 1.0f / 60.0f;
        sf::Clock _clock;
        GameDataRef _data = std::make_shared<GameData>();
        void run();

    };
}

