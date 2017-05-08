#include "tttmp.hpp"

tttmp::tttmp(int height, int width, const char* title) {
	gamewindow_.create(sf::VideoMode(height, width), title);

	sf::RectangleShape rect(sf::Vector2f(49, 49));
	rect.setFillColor(sf::Color::White);

	grid.push_back(rect);
	grid.push_back(rect);
	grid.push_back(rect);
	grid.push_back(rect);
	grid.push_back(rect);
	grid.push_back(rect);
	grid.push_back(rect);
	grid.push_back(rect);
	grid.push_back(rect);

	grid[1].setPosition(50, 0);
	grid[2].setPosition(100, 0);

	grid[3].setPosition(0, 50);
	grid[4].setPosition(50, 50);
	grid[5].setPosition(100, 50);

	grid[6].setPosition(0, 100);
	grid[7].setPosition(50, 100);
	grid[8].setPosition(100, 100);
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
	gamewindow_.clear(sf::Color::Black);

	sf::Vector2i mouse = sf::Mouse::getPosition(gamewindow_);

	for(int i = 0; i < 9; i++) {
		if(grid[i].getGlobalBounds().contains(mouse.x, mouse.y)) {
			grid[i].setFillColor(sf::Color::Red);
		}
		gamewindow_.draw(grid[i]);
	}

	gamewindow_.display();
}
