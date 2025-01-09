#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include "includes/Snake.h"

using namespace std;

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SnakeGame");    
    Snake snake;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Handle one-time actions (Pause maybe?)
            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case sf::Keyboard::Key::Escape:
                        cout << "PAUSE" << endl;
                        break;
                }
            }
        }

        // Player movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
			snake.move(sf::Keyboard::Key::W);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            snake.move(sf::Keyboard::Key::A);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            snake.move(sf::Keyboard::Key::S);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            snake.move(sf::Keyboard::Key::D);
        }


        window.clear();
        snake.draw(window);
        window.display();
    }

    return 0;
}