#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace game
{
    class MainMenuState : public State
    {
    public:
        MainMenuState(GameDataRef data);
        ~MainMenuState();
        void init();
        void handle_input();
        void update(float dt);
        void draw(float dt);

    private:
        GameDataRef _data;
        sf::Clock _clock;
        sf::Sprite _background;
        sf::Sprite _play_button;
        sf::Sprite _play_button_outer;
        sf::Sprite _title;

        void pause() override;

        void resume() override;


    };
}