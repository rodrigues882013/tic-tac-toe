#include <sstream>
#include <iostream>
#include <utility>
#include "../includes/MainMenuState.hpp"
#include "../includes/Definitions.hpp"
#include "../includes/GameState.hpp"


namespace game
{

	MainMenuState::MainMenuState(GameDataRef data) {
		this->_data = std::move(data);
	}

	game::MainMenuState::~MainMenuState() {
	}

	void MainMenuState::draw(float dt)
	{
		this->_data->window.clear();
		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_play_button);
		this->_data->window.draw(this->_play_button_outer);
		this->_data->window.draw(this->_title);

		this->_data->window.display();
	}

	void MainMenuState::init() {
		this->_data->assets.load_texture("Background", Constants::MAIN_MENU_BACKGROUND_FILEPATH);
		this->_data->assets.load_texture("Play Button", Constants::MAIN_MENU_PLAY_BUTTON);
		this->_data->assets.load_texture("Play Button Outer", Constants::MAIN_MENU_PLAY_BUTTON_OUTER);
		this->_data->assets.load_texture("Game Title", Constants::MAIN_MENU_TITLE_FILEPATH);

		this->_background.setTexture(this->_data->assets.get_texture("Background"));
		this->_play_button.setTexture(this->_data->assets.get_texture("Play Button"));
		this->_play_button_outer.setTexture(this->_data->assets.get_texture("Play Button Outer"));
		this->_title.setTexture(this->_data->assets.get_texture("Game Title"));

		this->_play_button.setPosition((Constants::WINDOW_WIDTH / 2) - (this->_play_button.getGlobalBounds().width / 2),
			(Constants::WINDOW_HEIGHT / 2) - (this->_play_button.getGlobalBounds().height / 2));

		this->_play_button_outer.setPosition((Constants::WINDOW_WIDTH / 2) - (this->_play_button_outer.getGlobalBounds().width / 2),
			(Constants::WINDOW_HEIGHT / 2) - (this->_play_button_outer.getGlobalBounds().height / 2));

		this->_title.setPosition((Constants::WINDOW_WIDTH / 2) - (this->_title.getGlobalBounds().width / 2),
			(Constants::WINDOW_HEIGHT / 2) - (this->_title.getGlobalBounds().height * 0.1));

	}

	void MainMenuState::handle_input()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (this->_data->inputs.is_sprite_clicked(this->_play_button, sf::Mouse::Left, this->_data->window))
			{
				this->_data->machine.add_state(StateRef(new GameState(_data)), true);
			}
		}
	}

	void MainMenuState::update(float dt)
	{

	}

	void MainMenuState::pause() {

	}

	void MainMenuState::resume() {

	}
}
