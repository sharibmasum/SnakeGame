#include <SFML/Graphics.hpp>
#include <iostream>
#include "snake.h"
#include "apple.h"

using namespace std;
int gameState = 0;

// ---- global variables -----------------------------------------

snake gameSnake(500, 500);
apple gameApple(600, 600);
bool isVisible[100] = {false};
int c = 0;

bool appleWasEatenLastFrame = false;

// ----------------------------------------------------------------

int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 1000),
                            "---Snake Game---");


    sf::Clock clock;
    sf::Time lastMoveTime = clock.getElapsedTime();

    sf::Font font;
    font.loadFromFile("/Users/sharibmasum/CLionProjects/snakeGame/arial.ttf");
    sf::Text text;
    text.setFont(font);


    text.setPosition(300, 180);

    bool spacepressed = false;

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        if (gameState == 0) {

            window.clear();

            if (gameSnake.checkCollisions()) {
                gameState = 1;
            }


            gameSnake.checkSnakeMovement();

            if ((clock.getElapsedTime() - lastMoveTime).asMilliseconds() >= 130) {
                gameSnake.moveSnake();
                lastMoveTime = clock.getElapsedTime();
            }

            isVisible[c] = true;


            for (int i = 0; i < 100; i++) {
                window.draw(gameSnake.drawRectangles(i, isVisible[i]));
            }


            window.draw(gameSnake.drawCircleHead());
            window.draw(gameApple.drawApple());

            vector<sf::Vector2f> positions;
            for (int i = 0; i < 100; i++) {
                positions.push_back(gameSnake.getBodyPosition(i));
            }

            if ((gameSnake.getHeadPosition() == gameApple.getPosition()) && !appleWasEatenLastFrame) {
                c++;
                gameApple.createNewPosition(positions);
            }

            appleWasEatenLastFrame = (gameSnake.getHeadPosition() == gameApple.getPosition());
            window.display();
        }

        if (gameState == 1) {
            window.clear();
            text.setString("Press space to try again");
            text.setFillColor(sf::Color::Red);
            text.setCharacterSize(20);
            window.draw(text);


            bool spacePressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);

            if (spacePressed && spacepressed == false)  {
                gameSnake.setHeadPosition();
                clock.restart();
                for (int i=0; i<100; i++) {
                    isVisible[i] = false;
                    c = 0;
                }
                gameState = 0;
            }

            spacePressed = spacepressed;

            window.display();

        }


        cout << gameState << endl;
    }
}
