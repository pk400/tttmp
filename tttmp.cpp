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

struct Grid {
	Grid(int h, int w) {
		rect.setSize(sf::Vector2f(h, w));
		rect.setFillColor(sf::Color::White);
	}
	void setPos(int x, int y) {
		rect.setPosition(sf::Vector2f(x, y));
	}
	sf::RectangleShape rect;
};

int main() {
	Window gw(149, 149, "Tic Tac Toe Multiplayer");

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

		// TODO: Turn this into an array/vector
		Grid
			g1(49, 49), g2(49, 49), g3(49, 49),
			g4(49, 49), g5(49, 49), g6(49, 49),
			g7(49, 49), g8(49, 49), g9(49, 49);

		g1.setPos(0, 0);
		g2.setPos(50, 0);
		g3.setPos(100, 0);

		g4.setPos(0, 50);
		g5.setPos(50, 50);
		g6.setPos(100, 50);

		g7.setPos(0, 100);
		g8.setPos(50, 100);
		g9.setPos(100, 100);

		gw.getWindow().clear(sf::Color::Black);

		gw.getWindow().draw(g1.rect);
		gw.getWindow().draw(g2.rect);
		gw.getWindow().draw(g3.rect);
		gw.getWindow().draw(g4.rect);
		gw.getWindow().draw(g5.rect);
		gw.getWindow().draw(g6.rect);
		gw.getWindow().draw(g7.rect);
		gw.getWindow().draw(g8.rect);
		gw.getWindow().draw(g9.rect);

		sf::Vector2i mousepos = sf::Mouse::getPosition(gw.getWindow());

		if(g1.rect.getGlobalBounds().contains(sf::Vector2f(mousepos.x, mousepos.y))) {
			std::cout << "g1" << std::endl;
		}

		gw.getWindow().display();
	}
}
