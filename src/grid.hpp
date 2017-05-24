#ifndef GRID_HPP_
#define GRID_HPP_

#include <SFML/Graphics.hpp>
#include <vector>
#include "settings.hpp"

enum State { EMPTY, CROSS, CIRCLE };

struct tSquare {
	sf::RectangleShape tsq;
	int state;
};

class Grid {
public:
	Grid();
	void initialize(const Settings& gs);
	std::vector<tSquare> getSquares();
	tSquare& operator[](int index) {
		return griddata_[index];
	}
private:
	std::vector<tSquare> griddata_;
};



#endif /* GRID_HPP_ */
