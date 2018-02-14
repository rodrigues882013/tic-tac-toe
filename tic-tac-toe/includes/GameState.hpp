#pragma once

#include "State.hpp"
#include "Game.hpp"
#include "AI.hpp"

namespace game
{
    class GameState : public State
    {
    public:

        GameState(GameDataRef data);

        ~GameState();

        void init();

        void handle_input();

        void update(float dt);

        void draw(float dt);


    private:
        void check_and_place_piece();
        void init_grid_piece();
        void init_grid_array();
        void load_texture();
        void set_positions();
        void check_player_has_won(int);
        void check_align_pieces_match(int, int, int, int, int, int, int);


        GameDataRef _data;
        sf::Sprite _background;
        sf::Sprite _pause_button;
        sf::Sprite _grid;
        sf::Sprite _grid_pieces[3][3];

        int grid_array[3][3];
        int turn;
        int game_state;
        AI *ai;
        sf::Clock _clock;


        void pause();

        void resume();
    };
}