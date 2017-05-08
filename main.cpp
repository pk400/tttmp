#include <iostream>
#include "tttmp.hpp"

int main(int argc, char** argv) {
	tttmp game(149, 149, "Tic Tac Toe Multiplayer");

	return game.run();
}
