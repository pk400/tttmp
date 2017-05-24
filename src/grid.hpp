#ifndef GRID_HPP_
#define GRID_HPP_

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
	void initialize();
	std::vector<tSquare> getSquares();
	tSquare& operator[](int index) {
		return griddata_[index];
	}
private:
	std::vector<tSquare> griddata_;
};



#endif /* GRID_HPP_ */
