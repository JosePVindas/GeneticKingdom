#ifndef OGRE_H
#define OGRE_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>


class Ogre
{
public:
    // public Method and attribute declararion
    bool isAlive = true;
    sf::Sprite getSprite();
    void kill();
    void Hit(int projectile,float damage);
    //void setPath(int[] path);
    void checkStats();
    float getSpeed();
    Ogre(float speed,float MagicRes, float ArrowRes, float BulletRes){
        Ogre::speed = speed;
        Ogre::MagicRes = MagicRes;
        Ogre::ArrowRes = ArrowRes;
        Ogre:: BulletRes = BulletRes;
        Ogre::Fitness = speed + MagicRes + ArrowRes + BulletRes;
    }
private:
    sf::Sprite sprite;
    //int[] path;
    float speed;
    float MagicRes;
    float ArrowRes;
    float BulletRes;
    float Life;
    float Fitness;
};

#endif // OGRE_H

