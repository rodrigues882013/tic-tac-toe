#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <array>
#include "Game.hpp"

namespace game
{
    class AI
    {
    public:
        AI(int, GameDataRef);
        ~AI();

        void place_piece(int(*grid_array)[3][3], sf::Sprite grid_pieces[3][3], int *game_state);

    private:
        void check_section(int x1,
                           int y1,
                           int x2,
                           int y2,
                           int _x,
                           int _y,
                           int piece_to_check,
                           int(*grid_array)[3][3],
                           sf::Sprite grid_piece[3][3]);

        void check_if_piece_is_empty(int _x,
                                     int _y,
                                     int(*grid_array)[3][3],
                                     sf::Sprite grid_piece[3][3]);

        int ai_piece;
        int player_piece;

        std::vector<std::array<int, 6>> check_match_vector;

        GameDataRef _data;




    };
}