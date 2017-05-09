#include <iostream>
#include "tttmp.hpp"

int main(int argc, char** argv) {
	int wsize = 150;
	tttmp game(wsize, wsize, "Tic Tac Toe Multiplayer");

	Settings gsettings;
	gsettings.sqsize 	= sf::Vector2f(wsize/3, wsize/3);
	gsettings.bgcolor 	= sf::Color::Black;
	gsettings.sqcolor 	= sf::Color::White;
	game.setSettings(gsettings);

	game.createGrid();

	return game.run();
}
