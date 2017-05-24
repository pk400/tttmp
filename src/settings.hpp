/*
 * settings.hpp
 *
 *  Created on: May 8, 2017
 *      Author: joel
 */

#ifndef SETTINGS_HPP_
#define SETTINGS_HPP_

#include <SFML/Graphics.hpp>

class Settings {
    public:
	static Settings* getInstance();
	void setSquareSize(sf::Vector2f);
	void setBgColor(sf::Color);
	void setSqColor(sf::Color);

	sf::Vector2f getSquareSize() const;
	sf::Color getBgColor() const;
	sf::Color getSqColor() const;
    private:
	static Settings* instance;
	Settings(){}
	sf::Vector2f sqsize;
	sf::Color bgcolor;
	sf::Color sqcolor;
};

#endif /* SETTINGS_HPP_ */
