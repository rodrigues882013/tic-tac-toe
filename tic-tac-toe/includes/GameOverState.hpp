#pragma once

#include "State.hpp"
#include "Game.hpp"

namespace game
{
    class GameOverState : public State
    {
    public:
        GameOverState(GameDataRef);
        ~GameOverState();
        void init();
        void handle_input();
        void update(float dt);
        void draw(float dt);

    private:
        GameDataRef _data;
        sf::Sprite _retry_button;
        sf::Sprite _home_button;
    };
}