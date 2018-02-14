
#include <SFML/Graphics.hpp>
#include "../includes/SplashState.hpp"
#include "../includes/Game.hpp"


namespace game {

	Game::~Game() {}

	Game::Game(int width, int height, std::string title) {
		_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);

		_data->machine.add_state(StateRef(new SplashState(this->_data)));

		this->run();


	}

	void Game::run() {
		float new_time, frame_time, interpolation;

		float current_time = this->_clock.getElapsedTime().asSeconds();
		float acc = 0.0f;

		while (this->_data->window.isOpen())
		{
			this->_data->machine.process_state_changes();
			new_time = this->_clock.getElapsedTime().asSeconds();
			frame_time = new_time - current_time;

			if (frame_time > 0.25f)
			{
				frame_time = 0.25f;
			}

			current_time = new_time;
			acc += frame_time;

			while (acc >= dt)
			{
				this->_data->machine.get_active_state()->handle_input();
				this->_data->machine.get_active_state()->update(dt);

				acc -= dt;
			}

			interpolation = acc / dt;
			this->_data->machine.get_active_state()->draw(interpolation);
		}
	}


}