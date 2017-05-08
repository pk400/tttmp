#ifndef TTTMP_HPP_
#define TTTMP_HPP_

#include <SFML/Graphics.hpp>
#include "settings.hpp"
#include "square.hpp"
#include <vector>

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
	std::vector<Square> grid;
	sf::RenderWindow gamewindow_;
	Settings gs_;
};

#endif /* TTTMP_HPP_ */
