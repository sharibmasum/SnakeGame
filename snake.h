//
// Created by sharib masum on 2024-05-11.
//

#ifndef SNAKEGAME_SNAKE_H
#define SNAKEGAME_SNAKE_H

#include <deque>

#include <SFML/Graphics.hpp>


class snake {
private:
    sf::Vector2f head_position;
    sf::RectangleShape snakeShape[100];
    sf::CircleShape headFace;
    std::deque<sf::Vector2f> positionHistory;

    float step = 100;
    float xDirection = 1;
    float yDirection = 0;

    sf::Vector2f face;

public:
    snake(float startX, float startY);

    sf::Vector2f getHeadPosition();

    sf::Vector2f getBodyPosition(int);

    void resetBodySizes();

    sf::RectangleShape drawRectangles(int, bool);

    sf::CircleShape drawCircleHead();

    void moveSnake();

    void checkSnakeMovement();

    bool checkCollisions();

    void setHeadPosition();

};


#endif //SNAKEGAME_SNAKE_H
