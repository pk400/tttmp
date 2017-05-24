#include "grid.hpp"
#include <iostream>

Grid::Grid() { }

void Grid::initialize() {
	sf::Vector2f temppos = sf::Vector2f(0, 0);
	sf::RectangleShape rect(Settings::getInstance()->getSquareSize());
	rect.setFillColor(Settings::getInstance()->getSqColor());
	rect.setOutlineColor(Settings::getInstance()->getBgColor());
	rect.setOutlineThickness(1);

	tSquare sq;
	sq.tsq = rect;
	sf::Vector2f size = Settings::getInstance()->getSquareSize();

	for(int i = 0; i < 9; i++) {
		griddata_.push_back(sq);
		// Set positions for display
		temppos.x = (i%3==0)?0:((i%2==0)?size.x-1:size.x*2);
		temppos.y = (i>5)?size.y*2:((i>2)?size.y:0);
		griddata_[i].tsq.setPosition(temppos);
	}
}

std::vector<tSquare> Grid::getSquares() {
	return griddata_;
}
