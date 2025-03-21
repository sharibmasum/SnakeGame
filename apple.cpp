//
// Created by sharib masum on 2024-05-11.
//

#include "apple.h"
#include <SFML/Graphics.hpp>
#include "snake.h"
#include <iostream>

using namespace std;

apple::apple(float startingX, float startingY) {
    apple_shape.setPosition(startingX + 50, startingY + 50);

    apple_shape.setRadius(20);
    apple_shape.setOrigin(20, 20);
    apple_shape.setFillColor(sf::Color::Red);
}

sf::CircleShape apple::drawApple() {
    return apple_shape;
}

sf::Vector2f apple::getPosition() {
    return sf::Vector2f (apple_shape.getPosition().x-50, apple_shape.getPosition().y-50);
}

void apple::createNewPosition (vector<sf::Vector2f> position) {
    sf::Vector2f newPosition;
    newPosition.x = rand() % 10 * 100;
    newPosition.y = rand() % 10 * 100;

    bool searchAll = true;
        while (searchAll) {
            for (int i=0; i<100; i++) {
                cout << position[i].x << ", " << position[i].y << endl;

                if (newPosition == position[i]) {
                    newPosition.x = rand() % 10 * 100;
                    newPosition.y = rand() % 10 * 100;
                }
            }

            searchAll = false;
        }


    newPosition.x += 50;
    newPosition.y += 50;

    apple_shape.setPosition(newPosition);
}