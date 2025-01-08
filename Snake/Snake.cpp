#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include <iostream>

using namespace std;

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Snake");
    sf::CircleShape player(100.f);
    player.setFillColor(sf::Color::Green);

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
			player.move(0, -0.1f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            player.move(-0.1f, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            player.move(0, 0.1f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            player.move(0.1f, 0);
        }


        window.clear();
        window.draw(player);
        window.display();
    }

    return 0;
}