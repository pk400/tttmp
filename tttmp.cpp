#include "tttmp.hpp"

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

	grid[1].square.setPosition(50, 0);
	grid[2].square.setPosition(100, 0);

	grid[3].square.setPosition(0, 50);
	grid[4].square.setPosition(50, 50);
	grid[5].square.setPosition(100, 50);

	grid[6].square.setPosition(0, 100);
	grid[7].square.setPosition(50, 100);
	grid[8].square.setPosition(100, 100);
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

	gamewindow_.display();
}

void tttmp::setSettings(const Settings& settings) {
	gs_ = settings;
}
