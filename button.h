#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>


class Button
{
public:
    Button();
    void Buttons(float posx, float posy,sf::Color color);
    void Pop(float posx,float posy, float width, float heigh);
    bool checkClick(sf::Vector2i  pos);
    bool hasTower;
    sf::RectangleShape getRect();
    sf::Vector2f getPosition();
    void setType(int type);
    void setLevel(int level);
    int getType();
    int getLevel();


    sf::RectangleShape getPerimeter();
    int i;
    int j;



private:
    sf::Vector2f position;
    sf::RectangleShape rect;
    sf::RectangleShape perimeter;
    int type;
    int level;


};

#endif // BUTTON_H
