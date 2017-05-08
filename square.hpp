#ifndef SQUARE_HPP_
#define SQUARE_HPP_

enum State { EMPTY, CROSS, CIRCLE };

struct Square {
	sf::RectangleShape square;
	int state;
};

#endif /* SQUARE_HPP_ */
