#include <utility>
#include <iostream>

#include "../includes/PauseState.hpp"
#include "../includes/Definitions.hpp"
#include "../includes/MainMenuState.hpp"

namespace game
{

	PauseState::PauseState(GameDataRef data) {
		this->_data = std::move(data);
	}

	PauseState::~PauseState()
	{

	}

	void PauseState::init()
	{
		this->_data->assets.load_texture("Pause Background", Constants::PAUSE_BACKGROUND_FILEPATH);
		this->_data->assets.load_texture("Resume Button", Constants::RESUME_BUTTON);
		this->_data->assets.load_texture("Home Button", Constants::HOME_BUTTON);

		_background.setTexture(this->_data->assets.get_texture("Pause Background"));
		_resume_button.setTexture(this->_data->assets.get_texture("Resume Button"));
		_home_button.setTexture(this->_data->assets.get_texture("Home Button"));


		_resume_button.setPosition((this->_data->window.getSize().x / 2) - (_resume_button.getLocalBounds().width / 2),
			(this->_data->window.getSize().y / 3) - (_resume_button.getLocalBounds().height / 2));

		_home_button.setPosition((this->_data->window.getSize().x / 2) - (_home_button.getLocalBounds().width / 2),
			(this->_data->window.getSize().y / 3 * 2) - (_home_button.getLocalBounds().height / 2));

	}

	void PauseState::handle_input()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (this->_data->inputs.is_sprite_clicked(this->_resume_button, sf::Mouse::Left, this->_data->window))
			{
				this->_data->machine.remove_state();
			}

			if (this->_data->inputs.is_sprite_clicked(this->_home_button, sf::Mouse::Left, this->_data->window))
			{
				this->_data->machine.remove_state();
				this->_data->machine.add_state(StateRef(new MainMenuState(_data)), true);
			}
		}
	}

	void PauseState::update(float dt) {

	}

	void PauseState::draw(float dt)
	{
		this->_data->window.clear();
		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_resume_button);
		this->_data->window.draw(this->_home_button);

		this->_data->window.display();
	}

	void PauseState::pause() {

	}

	void PauseState::resume() {

	}
}