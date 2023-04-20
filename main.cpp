#include <SFML/Animation.h>

int main(){
    //Create window
    sf::RenderWindow window(sf::VideoMode(512, 512), "CARALHO games", sf::Style::Close | sf::Style::Resize);

    //Create player
    sf::RectangleShape player(sf::Vector2f(60.0f, 90.0f));

    //Load texture and assign to playerTexture
    sf::Texture playerTexture;
    playerTexture.loadFromFile("assets/player_sprites.png");
    player.setTexture(&playerTexture);

    Animation animation(&playerTexture, sf::Vector2u(8, 3), 0.2f);

    float deltaTime = 0.0f;
    sf::Clock clock;

    //Event management
    while (window.isOpen()){
        deltaTime = clock.restart().asSeconds();
        sf::Event evento;
        while(window.pollEvent(evento)){
            switch(evento.type){
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::Resized:
                    printf("New window width: %i\nNew window height: %i\n", evento.size.width, evento.size.height);
                    break;
                
                case sf::Event::TextEntered:
                    if(evento.text.unicode < 128){
                        printf("%c", evento.text.unicode);
                    }
            }
        }

        //Shift to slow down movement
        float moveFactor = 1.0f;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)){
            moveFactor = 0.6f;
        }

        //Movement keys
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)){
            player.move(0.0f * moveFactor, -0.1f * moveFactor);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
            player.move(-0.1f * moveFactor, 0.0f * moveFactor);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)){
            player.move(0.0f * moveFactor, 0.1f * moveFactor);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
            player.move(0.1f * moveFactor, 0.0f * moveFactor);
        }

        animation.Update(0, deltaTime);
        player.setTextureRect(animation.uvRect);
        //Double buffering switches between front and back buffer so that display refreshes
        window.clear();
        window.draw(player);
        window.display();
    }
    return 0;
}