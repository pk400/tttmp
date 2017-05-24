#ifndef TTTMP_HPP_
#define TTTMP_HPP_

#include "grid.hpp"

class tttmp {
public:
	tttmp(int height, int width, const char* title);
	void 	createGrid();
	void 	setSettings(const Settings& settings);

	Settings& getSettings();
	Grid& 	getGrid();

	bool 	run();
	int 	getInput();
	void 	update();
	void 	draw();
	sf::RenderWindow& getWindow();
private:
	Grid grid_;
	sf::RenderWindow gamewindow_;
	Settings gs_;
};

#endif /* TTTMP_HPP_ */
