#include <SFML/Player.h>

int main(){
    //Create window
    sf::RenderWindow window(sf::VideoMode(512, 512), "TOUHOU games", sf::Style::Close | sf::Style::Resize);

    //Loads playerTexture
    sf::Texture playerTexture;
    playerTexture.loadFromFile("assets/player_sprites.png");

    //Creates player object with reference to texture pointer, imageCount, switchTime (animation speed) and playerspeed
    Player player(&playerTexture, sf::Vector2u(8, 3), 0.2f, 240.0f);

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

        //Double buffering switches between front and back buffer so that display refreshes
        window.clear();
        player.Draw(window);
        window.display();
    }
    return 0;
}