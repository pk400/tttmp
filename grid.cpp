#include "grid.hpp"
#include <iostream>

Grid::Grid() {

}

//Grid::Grid(const Settings& gs) {
void Grid::initialize(const Settings& gs) {
	sf::Vector2f temppos = sf::Vector2f(0, 0);
	sf::RectangleShape rect(gs.sqsize);
	rect.setFillColor(gs.sqcolor);

	tSquare sq;
	sq.tsq = rect;

	for(int i = 0; i < 9; i++) {
		griddata_.push_back(sq);
		// Set positions for display
		temppos.x = (i%3==0)?0:((i%2==0)?gs.sqsize.x:gs.sqsize.x*2);
		temppos.y = (i>5)?gs.sqsize.y*2:((i>2)?gs.sqsize.y:0);
		griddata_[i].tsq.setPosition(temppos);
	}
}

std::vector<tSquare> Grid::getSquares() {
	return griddata_;
}
