#include <iostream>
#include <SFML/Graphics.hpp>

class Window {
public:
	Window(int h, int w, const char* t)
		: _height(h), _width(w){
		_window.create(sf::VideoMode(h, w), t);
	}
	sf::RenderWindow& getWindow() {
		return _window;
	}
private:
	sf::RenderWindow _window;
	int _height;
	int _width;
};

int main() {
	Window gw(150, 150, "Tic Tac Toe Multiplayer");
	
	// Draw lines
	sf::Color linecolor = sf::Color::Black;

	sf::Vertex line1[] = {
			sf::Vertex(sf::Vector2f(50, 0), linecolor),
			sf::Vertex(sf::Vector2f(50, 150), linecolor)
	};

	sf::Vertex line2[] = {
			sf::Vertex(sf::Vector2f(100, 0), linecolor),
			sf::Vertex(sf::Vector2f(100, 150), linecolor)
	};

	sf::Vertex line3[] = {
			sf::Vertex(sf::Vector2f(0, 50), linecolor),
			sf::Vertex(sf::Vector2f(150, 50), linecolor)
	};

	sf::Vertex line4[] = {
			sf::Vertex(sf::Vector2f(0, 100), linecolor),
			sf::Vertex(sf::Vector2f(150, 100), linecolor)
	};

	// Game loop
	while(gw.getWindow().isOpen()) {
		// Handle input
		sf::Event event;

		while(gw.getWindow().pollEvent(event)) {
			switch(event.type) {
				case sf::Event::Closed:
					gw.getWindow().close();
					break;
			}
		}

		sf::Vertex line1[] = {
				sf::Vertex(sf::Vector2f(50, 0), sf::Color::Black),
				sf::Vertex(sf::Vector2f(50, 150), sf::Color::Black)
		};


		gw.getWindow().clear(sf::Color::White);

		gw.getWindow().draw(line1, 2, sf::Lines);
		gw.getWindow().draw(line2, 2, sf::Lines);
		gw.getWindow().draw(line3, 2, sf::Lines);
		gw.getWindow().draw(line4, 2, sf::Lines);

		sf::Vector2i mousepos = sf::Mouse::getPosition(gw.getWindow());

		if(mousepos.x > 0 && mousepos.x < 150 &&
				mousepos.y > 0 && mousepos.y < 150) {
			std::cout << mousepos.x <<
					" " << mousepos.y << std::endl;
				}

		gw.getWindow().display();
	}
}
