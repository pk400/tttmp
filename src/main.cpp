
#include <SFML/Graphics.hpp>
#include <iostream>
#include "tttmp.hpp"

Settings* Settings::instance = 0;

int main(int argc, char** argv) {
	int wsize = 600;
	tttmp game(wsize, wsize, "Tic Tac Toe Multiplayer");

	Settings::getInstance()->setSquareSize(sf::Vector2f(wsize/3, wsize/3));
	Settings::getInstance()->setBgColor(sf::Color::Black);
	Settings::getInstance()->setSqColor(sf::Color::White);

	game.createGrid();

	return game.run();
}
