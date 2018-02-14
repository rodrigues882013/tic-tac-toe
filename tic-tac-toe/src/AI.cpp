#include "../includes/AI.hpp"
#include "../includes/Definitions.hpp"
#include <iostream>

//using namespace std;

namespace game
{
    AI::AI(int player, GameDataRef data)
    {
        this->_data = data;
        this->player_piece = player;

        ai_piece = Constants::O_PIECE == player_piece ? Constants::X_PIECE : Constants::O_PIECE;

        check_match_vector.push_back({ 0, 2, 1, 2, 2, 2 });
        check_match_vector.push_back({ 0, 2, 0, 1, 0, 0 });
        check_match_vector.push_back({ 0, 2, 1, 1, 2, 0 });
        check_match_vector.push_back({ 2, 2, 1, 2, 0, 2 });
        check_match_vector.push_back({ 2, 2, 2, 1, 2, 0 });
        check_match_vector.push_back({ 2, 2, 1, 1, 0, 0 });
        check_match_vector.push_back({ 0, 0, 0, 1, 0, 2 });
        check_match_vector.push_back({ 0, 0, 1, 0, 2, 0 });
        check_match_vector.push_back({ 0, 0, 1, 1, 2, 2 });
        check_match_vector.push_back({ 2, 0, 2, 1, 2, 2 });
        check_match_vector.push_back({ 2, 0, 1, 0, 0, 0 });
        check_match_vector.push_back({ 2, 0, 1, 1, 0, 2 });
        check_match_vector.push_back({ 0, 1, 1, 1, 2, 1 });
        check_match_vector.push_back({ 1, 2, 1, 1, 1, 0 });
        check_match_vector.push_back({ 2, 1, 1, 1, 0, 1 });
        check_match_vector.push_back({ 1, 0, 1, 1, 1, 2 });
        check_match_vector.push_back({ 0, 1, 2, 1, 1, 1 });
        check_match_vector.push_back({ 1, 2, 1, 0, 1, 1 });
        check_match_vector.push_back({ 0, 2, 2, 0, 1, 1 });
        check_match_vector.push_back({ 2, 2, 0, 0, 1, 1 });
        check_match_vector.push_back({ 0, 2, 2, 2, 1, 2 });
        check_match_vector.push_back({ 0, 0, 2, 0, 1, 0 });
        check_match_vector.push_back({ 0, 2, 0, 0, 0, 1 });
        check_match_vector.push_back({ 2, 2, 2, 0, 2, 1 });

    }

    AI::~AI()
    {

    }
    void AI::place_piece(int(*grid_array)[3][3], sf::Sprite grid_pieces[3][3], int * game_state)
    {
        try
        {
            for (int i = 0; i < check_match_vector.size(); i++)
            {
                check_section(
                        check_match_vector[i][0],
                        check_match_vector[i][1],
                        check_match_vector[i][2],
                        check_match_vector[i][3],
                        check_match_vector[i][4],
                        check_match_vector[i][5],
                        Constants::AI_PIECE,
                        grid_array,
                        grid_pieces);
            }

            for (int i = 0; i < check_match_vector.size(); i++)
            {
                check_section(
                        check_match_vector[i][0],
                        check_match_vector[i][1],
                        check_match_vector[i][2],
                        check_match_vector[i][3],
                        check_match_vector[i][4],
                        check_match_vector[i][5],
                        Constants::PLAYER_PIECE,
                        grid_array,
                        grid_pieces);
            }

            check_if_piece_is_empty(1, 1, grid_array, grid_pieces);

            check_if_piece_is_empty(0, 2, grid_array, grid_pieces);
            check_if_piece_is_empty(2, 2, grid_array, grid_pieces);
            check_if_piece_is_empty(0, 0, grid_array, grid_pieces);
            check_if_piece_is_empty(2, 0, grid_array, grid_pieces);

            check_if_piece_is_empty(1, 2, grid_array, grid_pieces);
            check_if_piece_is_empty(0, 1, grid_array, grid_pieces);
            check_if_piece_is_empty(2, 1, grid_array, grid_pieces);
            check_if_piece_is_empty(1, 0, grid_array, grid_pieces);
        }
        catch (int error)
        {
            std::cout << "Error" << std::endl;
        }

        *game_state = Constants::STATE_PLAYING;

    }
    void AI::check_section(
            int x1,
            int y1,
            int x2,
            int y2,
            int _x,
            int _y,
            int piece_to_check,
            int(*grid_array)[3][3],
            sf::Sprite grid_pieces[3][3])
    {
        if ((*grid_array)[x1][y1] == piece_to_check && (*grid_array)[x2][y2] == piece_to_check)
        {
            if (Constants::EMPTY_PIECE == (*grid_array)[_x][_y])
            {
                (*grid_array)[_x][_y] = Constants::AI_PIECE;
                grid_pieces[_x][_y].setTexture(this->_data->assets.get_texture("O Piece"));
                grid_pieces[_x][_y].setColor(sf::Color(255, 255, 255, 255));

                throw -1;
            }
        }
    }

    void AI::check_if_piece_is_empty(
            int _x,
            int _y,
            int(*grid_array)[3][3],
            sf::Sprite grid_pieces[3][3])
    {
        if (Constants::EMPTY_PIECE == (*grid_array)[_x][_y])
        {
            (*grid_array)[_x][_y] = Constants::AI_PIECE;
            grid_pieces[_x][_y].setTexture(this->_data->assets.get_texture("O Piece"));
            grid_pieces[_x][_y].setColor(sf::Color(255, 255, 255, 255));

            throw -2;
        }
    }
}