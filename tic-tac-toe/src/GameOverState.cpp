#include "../includes/GameOverState.hpp"
#include "../includes/Definitions.hpp"
#include "../includes/MainMenuState.hpp"
#include "../includes/GameState.hpp"
#include <iostream>

namespace game
{
	GameOverState::GameOverState(GameDataRef data) {
		this->_data = std::move(data);
	}

	GameOverState::~GameOverState() {

	}

	void GameOverState::init()
	{
		this->_data->assets.load_texture("Retry Button", Constants::RETRY_BUTTON);
		this->_data->assets.load_texture("Home Button", Constants::HOME_BUTTON);

		_retry_button.setTexture(this->_data->assets.get_texture("Retry Button"));
		_home_button.setTexture(this->_data->assets.get_texture("Home Button"));


		_retry_button.setPosition((this->_data->window.getSize().x / 2) - (_retry_button.getLocalBounds().width / 2),
			(this->_data->window.getSize().y / 3) - (_retry_button.getLocalBounds().height / 2));

		_home_button.setPosition((this->_data->window.getSize().x / 2) - (_home_button.getLocalBounds().width / 2),
			(this->_data->window.getSize().y / 3 * 2) - (_home_button.getLocalBounds().height / 2));

	}

	void GameOverState::handle_input()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (this->_data->inputs.is_sprite_clicked(this->_retry_button, sf::Mouse::Left, this->_data->window))
			{
				this->_data->machine.add_state(StateRef(new GameState(_data)), true);
			}

			if (this->_data->inputs.is_sprite_clicked(this->_home_button, sf::Mouse::Left, this->_data->window))
			{
				this->_data->machine.add_state(StateRef(new MainMenuState(_data)), true);
			}
		}
	}

	void GameOverState::update(float dt) {

	}

	void GameOverState::draw(float dt)
	{
		this->_data->window.clear();
		this->_data->window.draw(this->_retry_button);
		this->_data->window.draw(this->_home_button);

		this->_data->window.display();
	}
}