#pragma once

#include <SFML/Graphics.hpp>

class Apple : public sf::Drawable {
public:
	Apple(float tileSize);
	void placeAppleRandomly(int tileSize, int xMax, int yMax);
	std::map<char, int> getAppleCoords();
	void draw(sf::RenderWindow& window);
private:
	sf::RectangleShape shape;
	static constexpr int xTileInit = 0;
	static constexpr int yTileInit = 0;
	int xTile;
	int yTile;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


