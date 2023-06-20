#include <SFML/Enemy.h>

Enemy::Enemy(sf::Texture* texture, float speed)
{
    this->speed = speed;
    faceRight = true;

    //Sets enemy properties
    body.setSize(sf::Vector2f(60.0f, 90.0f));
    body.setPosition(206.0f, 0.0f);
    body.setTexture(texture);
}

Enemy::~Enemy(){

}

void Enemy::Update(float deltaTime){
    sf::Vector2f movement(0.0f, 0.0f);
    float moveFactor = 1.0f;
    body.move(movement);
}

void Enemy::Draw(sf::RenderWindow& window){
    window.draw(body);
}