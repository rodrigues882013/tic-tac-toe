#include <SFML/Graphics.hpp>
#include "AssetManager.hpp"

namespace game
{
	void AssetManager::load_texture(std::string name, std::string file_name)
	{
		sf::Texture texture;

		if (texture.loadFromFile(file_name))
		{
			this->_textures[name] = texture;
		}
	}

	sf::Texture &AssetManager::get_texture(std::string name) {
		return this->_textures.at(name);
	}

	void AssetManager::load_font(std::string name, std::string file_name) {
		sf::Font font;

		if (font.loadFromFile(name))
		{
			this->_fonts[name] = font;
		}
	}

	sf::Font &AssetManager::get_font(std::string name) {
		return this->_fonts.at(name);
	}

	AssetManager::AssetManager() {

	}

	AssetManager::~AssetManager() {

	}
}
