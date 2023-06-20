#include <SFML/Player.h>
#include <SFML/Enemy.h>
#include <SFML/Audio.hpp>

int main(){
    //Create window
    sf::RenderWindow window(sf::VideoMode(512, 512), "Carlinhos Danmaku", sf::Style::Close | sf::Style::Resize);

    //Loads carlinhos music
    sf::Music music;
    if(!music.openFromFile("assets/sound/carlinhos.ogg"))
        return EXIT_FAILURE;

    //Plays carlinhos music
    music.play();   

    //Loads playerTexture and enemyTexture
    sf::Texture playerTexture;
    playerTexture.loadFromFile("assets/player_sprites.png");
    sf::Texture enemyTexture;
    enemyTexture.loadFromFile("assets/carlos.png");

    //Creates player object with reference to texture pointer, imageCount, switchTime (animation speed) and playerspeed
    Player player(&playerTexture, sf::Vector2u(8, 3), 0.2f, 240.0f);
    //Creates enemy object with no animation, only texture pointer and speed
    Enemy enemy(&enemyTexture, 240.0f);

    //deltaTime variable initialization
    //This implementation reduces variance between fast and slow PCs.
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
            }
        }

        //Calls update to 
        player.Update(deltaTime);
        enemy.Update(deltaTime);

        //Double buffering switches between front and back buffer so that display refreshes
        window.clear();
        player.Draw(window);
        enemy.Draw(window);
        window.display();
    }
    return 0;
}