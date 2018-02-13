#pragma once

#include "Game.hpp"

namespace game
{
    class PauseState : public State
    {
    public:
        PauseState(GameDataRef data);
        ~PauseState();
        void init();
        void handle_input();
        void update(float dt);
        void draw(float dt);

    private:
        GameDataRef _data;
        sf::Sprite _background;
        sf::Sprite _resume_button;
        sf::Sprite _home_button;

        void pause() override;

        void resume() override;
    };
}