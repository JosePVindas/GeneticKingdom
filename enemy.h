#ifndef ENEMY_H
#define ENEMY_H

#include<SFML/Main.hpp>
#include<SFML/Graphics.hpp>


class Enemy
{
public:
    Enemy();
    void Enemies(int type,float arrow,float magic,float bullet);
    sf::RectangleShape getRect();
    void kill();
    void hit(int projectile);
    int getType();

private:
    float arrow;
    float magic;
    float bullet;
    float life;

    int type;


};




#endif // ENEMY_H
