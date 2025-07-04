#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Snake {
public:
	Snake(float tileSize, int headTileX, int headTileY, sf::Color colorHead, sf::Color colorTail);
	void move(sf::Vector2f newPosition);
	void draw(sf::RenderWindow& window);
	std::map<char, int> getHeadTileCoords();
	void setHeadTileCoords(int x, int y);
	void addSegment();
	sf::Vector2f getTailEnd();

private:
	std::vector<sf::RectangleShape> body;
	int tileSize;
	int headTileX;
	int headTileY;
	sf::Color headColor;
	sf::Color tailColor;
	sf::Vector2f tailEnd;
};

