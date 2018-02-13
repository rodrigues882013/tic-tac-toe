#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace game
{
    class SplashState : public State
    {
    public:
        SplashState(GameDataRef data);

        ~SplashState();

        void init();

        void handle_input();

        void update(float dt);

        void draw(float dt);

    private:
        GameDataRef _data;
        sf::Clock _clock;
        sf::Sprite _background;

        void pause() override;

        void resume() override;


    };
}