#include <iostream>
#include "tttmp.hpp"

int main(int argc, char** argv) {
	tttmp game(149, 149, "Tic Tac Toe Multiplayer");

	Settings gsettings;
	gsettings.sqsize 	= sf::Vector2f(49, 49);
	gsettings.bgcolor 	= sf::Color::Black;
	gsettings.sqcolor 	= sf::Color::White;
	game.setSettings(gsettings);

	game.createGrid();

	return game.run();
}
