
#include <SFML/Graphics.hpp>
#include "../includes/Game.hpp"
#include "../includes/Definitions.hpp"


int main(char* args)
{
	game::Game(game::Constants::WINDOW_WIDTH, game::Constants::WINDOW_HEIGHT, "SFML Tutorial");

	return EXIT_SUCCESS;

}