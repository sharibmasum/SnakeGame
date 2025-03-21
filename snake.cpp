//
// Created by sharib masum on 2024-05-11.
//

#include "snake.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <deque>

using namespace std;

snake::snake(float startX, float startY) {
    head_position.x = startX;
    head_position.y = startY;

    snakeShape[0].setFillColor(sf::Color::Green);
    snakeShape[0].setSize(sf::Vector2f(100, 100));
    snakeShape[0].setPosition(head_position);


    headFace.setRadius(20.f);
    headFace.setOrigin(20, 20);
    face.x = 100;
    face.y= 50;
    headFace.setFillColor(sf::Color::Red);

}


sf::Vector2f snake::getHeadPosition() {
    return head_position;
}

sf::Vector2f snake::getBodyPosition(int whichOne) {
    return snakeShape[whichOne].getPosition();
}

void snake::resetBodySizes() {
    for (int i=1; i< positionHistory.size(); i++) {
        snakeShape[i].setSize(sf::Vector2f (0,0));
    }
}

void snake::checkSnakeMovement() {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && xDirection != -1) {
        xDirection = 1;
        yDirection = 0;

        face.x = 100;
        face.y = 50;

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && xDirection != 1) {
        xDirection = -1;
        yDirection = 0;

        face.x = 0;
        face.y = 50;

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && yDirection != -1) {
        yDirection = 1;
        xDirection = 0;

        face.x = 50;
        face.y = 100;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && yDirection != 1) {
        yDirection = -1;
        xDirection = 0;

        face.x = 50;
        face.y = 0;
    }
}

bool snake::checkCollisions() {
    for (int i = 1; i < positionHistory.size(); ++i) {
        if (head_position == positionHistory[i] && snakeShape[i].getSize() == sf::Vector2f (100,100)) {
           return true;
        }
    }

    if (head_position.x < 0.f || head_position.x > 900.f || head_position.y < 0.f || head_position.y > 900.f) {
        return true;
    }
}

void snake::moveSnake() {
    head_position.x += step * xDirection;
    head_position.y += step * yDirection;

    positionHistory.push_front(head_position);
    if (positionHistory.size() > 100) {
        positionHistory.pop_back();
    }
    for (int i = 0; i < 100; ++i) {
        if (i < positionHistory.size()) {
            snakeShape[i].setPosition(positionHistory[i]);
        }
    }

    snakeShape[0].setPosition(head_position);
}

sf::RectangleShape snake::drawRectangles(int i, bool visible) {

    if (visible) {
        if (i % 2 == 0) {
            snakeShape[i].setFillColor(sf::Color::Green);
        } else {
            snakeShape[i].setFillColor(sf::Color::Blue);
        }
        snakeShape[i].setSize(sf::Vector2f(100, 100));
        return snakeShape[i];
    }

    snakeShape[0].setFillColor(sf::Color::Green);
    snakeShape[0].setPosition(getHeadPosition());
    return snakeShape[0];
}

sf::CircleShape snake::drawCircleHead() {
    headFace.setPosition(getHeadPosition() + face);
    return headFace;
}

void snake::setHeadPosition() {
    snakeShape[0].setPosition(500,500);
}