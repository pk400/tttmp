#ifndef TTTMP_HPP_
#define TTTMP_HPP_

#include <SFML/Graphics.hpp>
#include <vector>

class tttmp {
public:
	tttmp(int height, int width, const char* title);
	bool run();
	int getInput();
	void update();
	void draw();
private:
	std::vector<sf::RectangleShape> grid;
	sf::RenderWindow gamewindow_;
};

#endif /* TTTMP_HPP_ */
