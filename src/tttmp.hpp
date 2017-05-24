#ifndef TTTMP_HPP_
#define TTTMP_HPP_

#include "grid.hpp"

class tttmp {
public:
	tttmp(int height, int width, const char* title);
	void 	createGrid();

	Grid& 	getGrid();

	bool 	run();
	int 	getInput();
	void 	update();
	void 	draw();
	sf::RenderWindow& getWindow();
private:
	Grid grid_;
	sf::RenderWindow gamewindow_;
};

#endif /* TTTMP_HPP_ */
