#include "tttmp.hpp"
#include <iostream>

tttmp::tttmp(int height, int width, const char* title) {
	gamewindow_.create(sf::VideoMode(height, width), title);
}

bool tttmp::run() {
	bool exitcode = false;

	while(gamewindow_.isOpen()) {
		int ui = getInput();
		if(ui != 0) {
			exitcode = true;
			return exitcode;
		}

		update();

		draw();
	}

	return exitcode;
}

void tttmp::createGrid() {
	sf::RectangleShape rect(gs_.sqsize);
	rect.setFillColor(gs_.sqcolor);

	Square sq;
	sq.square = rect;

	grid.push_back(sq);
	grid.push_back(sq);
	grid.push_back(sq);
	grid.push_back(sq);
	grid.push_back(sq);
	grid.push_back(sq);
	grid.push_back(sq);
	grid.push_back(sq);
	grid.push_back(sq);

	for(int i = 0; i < 9; i++) {
		// Default position for top left square
		sf::Vector2f pos = sf::Vector2f(0, 0);

		/*	-------------
		 * 	| 0 | 1 | 2 |
		 *  | 3 | 4 | 5 |
		 *  | 6 | 7 | 8 |
		 *  -------------
		 */

		pos.x = (i%3==0)?0:((i%2==0)?gs_.sqsize.x:gs_.sqsize.x*2);
		pos.y = (i>5)?gs_.sqsize.y*2:((i>2)?gs_.sqsize.y:0);

		grid[i].square.setPosition(pos);
	}
}

int tttmp::getInput() {
	int retvalue = 0;

	sf::Event event;

	while(gamewindow_.pollEvent(event)) {
		switch(event.type) {
		case sf::Event::Closed:
			gamewindow_.close();
			break;
			retvalue = 1;
		}
	}

	return retvalue;
}

void tttmp::update() {

}

void tttmp::draw() {
	gamewindow_.clear(gs_.bgcolor);

	sf::Vector2i mouse = sf::Mouse::getPosition(gamewindow_);

	for(int i = 0; i < 9; i++) {
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
				grid[i].square.getGlobalBounds().contains(mouse.x, mouse.y)) {
			grid[i].square.setFillColor(sf::Color::Red);
			grid[i].state = CROSS;
		}
		gamewindow_.draw(grid[i].square);
	}

	// Draw line
	sf::Vertex line[] = {
		sf::Vertex(sf::Vector2f());
	};

	gamewindow_.display();
}

void tttmp::setSettings(const Settings& settings) {
	gs_ = settings;
}
