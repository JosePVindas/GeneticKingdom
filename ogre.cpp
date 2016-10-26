#include "ogre.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>

using namespace std;



    // Switch boolean state so the GUI knows not to draw this Ogre
   void Ogre::kill() {
        isAlive = false;
    }
    // Returns the Sprite of the Ogre so the GUI can draw it

    // Called when a collision is detected, evaluates the king of projectile and the damage it produces
    // so it knows what to do about it.
   void Ogre::Hit(int projectile,float damage){
        switch (projectile){

        case 0:
        {float temp = damage / Ogre::MagicRes;
            Ogre::Life = Ogre::Life - temp;
            checkStats();
            break;}


        case 1:
        {float temp = damage / Ogre::ArrowRes;
            Ogre::Life = Ogre::Life - temp;
            checkStats();
            break;}


        case 2:
        {float temp = damage / Ogre::BulletRes;
            Ogre::Life = Ogre::Life - temp;
            checkStats();
            break;}
        }
    }
    //Checks Ogre stats in case it has been killed.
    void Ogre::checkStats(){
        if(Ogre::Life <= 0.0){
            Ogre::kill();
        }
    }

    sf::Sprite Ogre::getSprite(){
        sf::Texture playerTexture;
            if (!playerTexture.loadFromFile("C:/Users/jpvin/Documents/SpriteResources/PlayerSprites.png")){

                //cout << "no funca :(" << endl;

            }
            sf::Sprite playerSprites;
            playerSprites.setTexture(playerTexture);
            //playerSprites.setPosition(200,window.getSize().y/2);
            playerSprites.setTextureRect(sf::IntRect(32*6,0,32,32));

            return playerSprites;

    }

  float Ogre::getSpeed(){
       return Ogre::speed;
   }


