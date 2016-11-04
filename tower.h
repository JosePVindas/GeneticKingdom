#ifndef TOWER_H
#define TOWER_H

#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>


class Tower
{
public:
    Tower();
    void Towers(float posx, float posy);
    bool checkClick (sf::Vector2i pos);
    bool isTower;
    sf::RectangleShape getPerimeter();
    sf::Sprite getSprite();
    sf::RectangleShape shoot(sf::Vector2f pos);
    void upgrade();
    void Sell();
    void NewTower(int type);
    sf::Vector2f getPosition();

private:
    sf::RectangleShape perimeter;
    sf::Sprite sprite;
    bool shooting;
    int type;
    int power;
    bool isSold;
    sf::Vector2f position;
    float posx;
    float posy;

};

#endif // TOWER_H
