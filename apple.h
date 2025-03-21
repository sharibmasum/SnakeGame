//
// Created by sharib masum on 2024-05-11.
//

#ifndef SNAKEGAME_APPLE_H
#define SNAKEGAME_APPLE_H
#include <SFML/Graphics.hpp>

class apple {
private:
    sf::Vector2f apple_position;
    sf::CircleShape apple_shape;


public:
    apple(float x, float y);

    sf::Vector2f getPosition ();
    sf::CircleShape drawApple();

    void createNewPosition(std::vector<sf::Vector2f>);
};

#endif //SNAKEGAME_APPLE_H
