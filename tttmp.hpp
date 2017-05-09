#ifndef TTTMP_HPP_
#define TTTMP_HPP_

#include "grid.hpp"

class tttmp {
public:
	tttmp(int height, int width, const char* title);
	bool 	run();
	void 	createGrid();
	int 	getInput();
	void 	update();
	void 	draw();
	void 	setSettings(const Settings& settings);
private:
	Grid grid_;
	sf::RenderWindow gamewindow_;
	Settings gs_;
};

#endif /* TTTMP_HPP_ */
