#include <SFML/Player.h>

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
    animation(texture, imageCount, switchTime)
{
    this->speed = speed;
    row = 0;
    faceRight = true;

    //Sets player properties
    body.setSize(sf::Vector2f(60.0f, 90.0f));
    body.setPosition(206.0f, 206.0f);
    body.setTexture(texture);
}

Player::~Player(){

}

void Player::Update(float deltaTime){
    sf::Vector2f movement(0.0f, 0.0f);
    float moveFactor = 1.0f;

    //Shift slows down your movement speed
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
        moveFactor = 0.6f;

    //Movement keymapping
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        movement.y -= speed * deltaTime * moveFactor;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        movement.x -= speed * deltaTime * moveFactor;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        movement.y += speed * deltaTime * moveFactor;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        movement.x += speed * deltaTime * moveFactor;
    
    if(movement.x == 0.0f){
        row = 0;
    }else{
        row = 1;

        if(movement.x > 0.0f)
            faceRight = true;
        else
            faceRight = false;
    }
    animation.Update(row, deltaTime, faceRight);
    body.setTextureRect(animation.uvRect);
    body.move(movement);
}

void Player::Draw(sf::RenderWindow& window){
    window.draw(body);
}