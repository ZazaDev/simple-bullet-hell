#include <SFML/Animation.h>

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime){
    this->imageCount = imageCount;
    this->switchTime = switchTime;
    totalTime = 0.0f;
    currentImage.x = 0;

    //Gets texture size dividing the total size by the number of sprites in each row
    uvRect.width = texture->getSize().x / float(imageCount.x);
    uvRect.height = texture->getSize().y / float(imageCount.y);
}

Animation::~Animation(){

}

void Animation::Update(int row, float deltaTime, bool faceRight){
    currentImage.y = row;
    totalTime += deltaTime;
    if(totalTime >= switchTime){
        totalTime -= switchTime;
        currentImage.x++;
        if(currentImage.x >= imageCount.x){
            currentImage.x = 0;
        }
    }
    uvRect.top = currentImage.y * uvRect.height;

    if(faceRight){
        uvRect.left = currentImage.x * uvRect.width;
        uvRect.width = abs(uvRect.width);
    }else{
        //This is a tricky hack that moves the width start point from the left of the image to the right of the image
        //To do this we have to take the absolute negative value of the normal width (from left to right)
        uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
        uvRect.width = -abs(uvRect.width);
    }
}