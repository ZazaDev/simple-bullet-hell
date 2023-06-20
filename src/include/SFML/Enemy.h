#pragma once
#include <SFML/Graphics.hpp>

class Enemy{
public:
    Enemy(sf::Texture* texture, float speed);
    ~Enemy();

    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);

private:
    sf::RectangleShape body;
    float speed;
    bool faceRight;
};