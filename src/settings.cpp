#include "settings.hpp"

Settings* Settings::getInstance() {
	if(!instance) {
		instance = new Settings();
	}
	return instance;
}

void Settings::setSquareSize(sf::Vector2f size) {
	sqsize = size;
}

void Settings::setBgColor(sf::Color colour) {
	bgcolor = colour;
}

void Settings::setSqColor(sf::Color colour) {
	sqcolor = colour;
}

sf::Vector2f Settings::getSquareSize() const {
	return sqsize;
}

sf::Color Settings::getBgColor() const {
	return bgcolor;
}

sf::Color Settings::getSqColor() const {
	return sqcolor;
}
