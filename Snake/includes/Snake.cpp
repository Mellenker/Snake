#include "Snake.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Snake::Snake() {
    sf::RectangleShape segment(sf::Vector2f(30.f, 30.f));
    segment.setFillColor(sf::Color::Green);
    segment.setPosition(100.f, 100.f);
    body.push_back(segment);
    direction = sf::Vector2f(20.f, 0.f);
}

void Snake::move(sf::Keyboard::Key key) {
	switch (key) {
		case sf::Keyboard::Key::W:
			direction = sf::Vector2f(0, -0.1f);
			break;
		case sf::Keyboard::Key::A:
			direction = sf::Vector2f(-0.1f, 0);
			break;
		case sf::Keyboard::Key::S:
			direction = sf::Vector2f(0, 0.1f);
			break;
		case sf::Keyboard::Key::D:
			direction = sf::Vector2f(0.1f, 0);
			break;
	}
	
	sf::RectangleShape segment = body.front();
	
	segment.setPosition(segment.getPosition() + direction);

	body.insert(body.begin(), segment);
	body.pop_back();
}

void Snake::draw(sf::RenderWindow &window) {
    for (auto &segment : body) {
        window.draw(segment);
    }
}
