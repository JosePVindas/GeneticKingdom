#include "tower.h"

Tower::Tower()
{

}

void Tower::Towers(float posx, float posy){
    Tower::position = sf::Vector2f(posx,posy);
    Tower::isTower = false;
    Tower::shooting = false;
    Tower::posx = posx;
    Tower::posy = posy;
}


bool Tower::checkClick(sf::Vector2i pos){

    if(pos.x>Tower::position.x && pos.x < Tower::position.x + 66){
        if (pos.y > Tower::position.y && pos.y < Tower::position.y + 66){


            return true;
        }
    }
    return false;

}

sf::RectangleShape Tower::getPerimeter(){

    int x = Tower::position.x -(66*Tower::power);
    int x2 = Tower::position.x +66+(66*Tower::power);
    int y = Tower::position.y -(66*Tower::power);
    int y2 = Tower::position.y +66+(66*Tower::power);

    sf::RectangleShape per;
    per.setPosition(sf::Vector2f(x,y));
    per.setSize(sf::Vector2f(x2,y2));

    return per;
}

sf::Sprite getSprite(){
    sf::Texture texture;
    texture.loadFromFile("Resources/TowerSprite.png");

    sf::Sprite sprite;
    sprite.setTexture(texture);
   // sprite.setPosition(sf::Vector2f(Tower::posx,Tower::posy));

    return sprite;

}

void Tower::Sell(){
    Tower::isTower = false;
}

void Tower::upgrade(){
    if (Tower::power < 3){
        Tower::power ++;

    }

}

void Tower::NewTower(int type){
    Tower::type = type;
    Tower::isTower = true;

}

sf::Vector2f Tower::getPosition(){
    return Tower::position;
}

