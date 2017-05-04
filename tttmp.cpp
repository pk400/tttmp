#include <iostream>
#include <SFML/Graphics.hpp>

class Window {
public:
	Window(int h, int w, const char* t)
		: _window(new sf::RenderWindow()) {
		_window->create(sf::VideoMode(h, w), t);
	}
	sf::RenderWindow* getWindow() {
		return _window;
	}
private:
	sf::RenderWindow* _window;
	int _height;
	int _width;
};

int main() {
	Window gw(800, 400, "Tic Tac Toe Multiplayer");
	
	// Game loop
	while(gw.getWindow()->isOpen()) {
		// Handle input
		sf::Event event;

		while(gw.getWindow()->pollEvent(event)) {
			switch(event.type) {
				case sf::Event::Closed:
					gw.getWindow()->close();
					break;
			}
		}

		gw.getWindow()->display();
	}
}
