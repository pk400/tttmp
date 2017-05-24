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
	grid_.initialize();
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
	sf::Vector2i mouse = sf::Mouse::getPosition(gamewindow_);

	for(int i = 0; i < 9; i++) {
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if(grid_[i].tsq.getGlobalBounds().contains(mouse.x, mouse.y)) {
				grid_[i].tsq.setFillColor(sf::Color::Red);
				grid_[i].state = CROSS;
			}
		}
	}
}

void tttmp::draw() {
	gamewindow_.clear(Settings::getInstance()->getBgColor());

	for(int i = 0; i < 9; i++) {
		gamewindow_.draw(grid_[i].tsq);
	}

	gamewindow_.display();
}

Grid& tttmp::getGrid() {
	return grid_;
}

