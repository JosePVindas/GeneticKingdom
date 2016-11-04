#include "button.h"

Button::Button()
{

}

void Button::Buttons(float posx, float posy,sf::Color color){
    Button::position = sf::Vector2f(posx,posy);
    sf::RectangleShape rect;
    rect.setFillColor(color);
    rect.setPosition(Button::position);
    rect.setSize(sf::Vector2f(66,66));

    Button::rect = rect;
    Button::hasTower = false;




}


void Button::Pop(float posx, float posy,float width, float heigh){

    Button::position = sf::Vector2f(posx,posy);

    sf::RectangleShape rect;
    rect.setPosition(Button::position);
    rect.setSize(sf::Vector2f(width,heigh));

    Button::rect = rect;
    Button::hasTower = false;

}

bool Button::checkClick(sf::Vector2i pos){

    if(pos.x>Button::position.x && pos.x < Button::position.x + Button::rect.getSize().x){
        if (pos.y > Button::position.y && pos.y < Button::position.y + Button::rect.getSize().y){


            return true;
        }
    }
    return false;

}

sf::RectangleShape Button::getRect(){
    return Button::rect;
}

sf::Vector2f Button::getPosition(){
    return Button::position;
}

void Button::setType(int type){
    Button::type = type;
}

void Button::setLevel(int level){
    Button::level = level;
}

int Button::getLevel(){
    return Button::level;
}

int Button::getType(){
    return Button::type;
}

