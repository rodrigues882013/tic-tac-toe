#include <iostream>
#include <utility>
#include "GameState.hpp"
#include "Definitions.hpp"
#include "PauseState.hpp"

namespace game
{

	GameState::GameState(GameDataRef data) 
	{
		this->_data = std::move(data);
	}

	GameState::~GameState() 
	{

	}

	void GameState::init()
	{
		game_state = Constants::STATE_PLAYING;
		turn = Constants::PLAYER_PIECE;

		load_texture();
		set_positions();
		init_grid_piece();
		init_grid_array();
	}

	void GameState::handle_input() 
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (this->_data->inputs.is_sprite_clicked(this->_pause_button, sf::Mouse::Left, this->_data->window))
			{
				this->_data->machine.add_state(StateRef(new PauseState(_data)), false);
			}
			else if (this->_data->inputs.is_sprite_clicked(this->_grid, sf::Mouse::Left, this->_data->window))
			{
				this->check_and_place_piece();
			}
		}
	}

	void GameState::update(float dt)
	{

	}

	void GameState::draw(float dt) 
	{
		this->_data->window.clear();
		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_pause_button);
		this->_data->window.draw(this->_grid);

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				this->_data->window.draw(this->_grid_pieces[i][j]);
			}
		}

		this->_data->window.display();
	}

	void GameState::pause()
	{

	}

	void GameState::resume()
	{

	}

	void GameState::check_and_place_piece()
	{
		sf::Vector2i touch_point = this->_data->inputs.get_mouse_position(this->_data->window);
		sf::FloatRect grid_size = _grid.getGlobalBounds();

		sf::Vector2f gap_outside_of_grid = sf::Vector2f((Constants::WINDOW_WIDTH - grid_size.width) / 2,
			(Constants::WINDOW_HEIGHT - grid_size.height) / 2);

		sf::Vector2f grid_local_touch_pos = sf::Vector2f((touch_point.x - gap_outside_of_grid.x),
			(touch_point.y - gap_outside_of_grid.y));

		sf::Vector2f grid_section_size = sf::Vector2f(grid_size.width/3, grid_size.height/3);

		int column, row;

		if (grid_local_touch_pos.x < grid_section_size.x)
		{
			column = 1;
		}
		else if (grid_local_touch_pos.x < grid_section_size.x * 2)
		{
			column = 2;
		}
		else if (grid_local_touch_pos.x < grid_size.width)
		{
			column = 3;
		}

		if (grid_local_touch_pos.y < grid_section_size.y)
		{
			row = 1;
		}
		else if (grid_local_touch_pos.y < grid_section_size.y * 2)
		{
			row = 2;
		}
		else if (grid_local_touch_pos.y < grid_size.height)
		{
			row = 3;
		}

		if (grid_array[column - 1][row - 1] == Constants::EMPTY_PIECE)
		{
			grid_array[column - 1][row - 1] = turn;

			if (Constants::PLAYER_PIECE == turn)
			{
				_grid_pieces[column - 1][row - 1].setTexture(this->_data->assets.get_texture("X Piece"));	
				turn = Constants::AI_PIECE;
			}
			else if (Constants::AI_PIECE == turn)
			{
				_grid_pieces[column - 1][row - 1].setTexture(this->_data->assets.get_texture("O Piece"));
				turn = Constants::PLAYER_PIECE;
			}

			_grid_pieces[column - 1][row - 1].setColor(sf::Color(255, 255, 255, 255));
		}


	}

	void GameState::init_grid_piece()
	{
		sf::Vector2u tempSprinteSize = this->_data->assets.get_texture("X Piece").getSize();

		for (int i = 0; i<3; i++)
		{
			for (int j = 0; j<3; j++)
			{
				_grid_pieces[i][j].setTexture(this->_data->assets.get_texture("X Piece"));
				_grid_pieces[i][j].setPosition(_grid.getPosition().x + (tempSprinteSize.x * i) - 7,
					_grid.getPosition().y + (tempSprinteSize.y * j) - 7);

				_grid_pieces[i][j].setColor(sf::Color(255, 255, 255, 0));
			}
		}

	}

	void GameState::init_grid_array()
	{
		for (int i = 0; i<3; i++)
		{
			for (int j = 0; j<3; j++)
			{
				grid_array[i][j] = Constants::EMPTY_PIECE;
			}
		}
	}

	void GameState::load_texture()
	{
		this->_data->assets.load_texture("Pause Button", Constants::PAUSE_BUTTON);
		this->_data->assets.load_texture("Grid", Constants::GRID_SPRITE_FILE_PATH);
		this->_data->assets.load_texture("X Piece", Constants::X_PIECE_FILEPATH);
		this->_data->assets.load_texture("O Piece", Constants::O_PIECE_FILEPATH);


		_background.setTexture(this->_data->assets.get_texture("Background"));
		_pause_button.setTexture(this->_data->assets.get_texture("Pause Button"));
		_grid.setTexture(this->_data->assets.get_texture("Grid"));
	}

	void GameState::set_positions()
	{
		_pause_button.setPosition(this->_data->window.getSize().x - _pause_button.getLocalBounds().width,
			this->_data->window.getPosition().y);

		_grid.setPosition((Constants::WINDOW_WIDTH / 2) - (_grid.getGlobalBounds().width / 2),
			(Constants::WINDOW_HEIGHT / 2) - (_grid.getGlobalBounds().height / 2));
	}
}