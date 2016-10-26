
#include <QApplication>
#include <iostream>

#include <mymouse.h>
#include <ogre.h>

// Graphic specific Includes.

// SFML is a simple C++ library for displaying graphics
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <SFML/Audio.hpp>

using namespace std;

/**
 * @brief main
 *
 * main is the default metod that is launch at application startup,
 * it runs the main game loop and displays everything to the window.
 *
 * @return exit number at close event
 */
int main(int argc, char *argv[]){



    //Define int for simple handling of sprite issues
    int isInGame = 0;
    int shoot = 0;

    //Test for Ogre movement and stuff
    Ogre ogre = Ogre::Ogre(0.5,2.0,2.0,2.0) ;

    //Create the main window
    sf::RenderWindow window (sf::VideoMode(1920,1080),"GeneticKingdom",sf::Style::Fullscreen);

    //Load Background Image

    sf::Texture menu;
    if (!menu.loadFromFile("C:/Users/jpvin/Documents/SpriteResources/menu_bg.jpg")){

        return EXIT_FAILURE;
    }

    //Create background sprite
    sf::Sprite menubg;
    menubg.setTexture(menu);

    //Load Background Image

    sf::Texture background;
    if (!background.loadFromFile("C:/Users/jpvin/Documents/SpriteResources/game_bg.jpg")){

        return EXIT_FAILURE;
    }

    //Load Background Music

   /** sf::Music music;
    if (!music.openFromFile("C:/Users/jpvin/Documents/SpriteResources/bgMusic.ogg")){

        cout << "Problem with music" << endl;

    }**/





    //create test rectangle
        sf::RectangleShape test;
        test.setFillColor(sf::Color::Green);
        test.setPosition(1920,1000);
        test.setSize(sf::Vector2f(10,10));

    //Create background sprite
    sf::Sprite bg;
    bg.setTexture(background);

    //Start Game Loop
    while (window.isOpen()){

        //Handle events
        sf::Event event;
        while (window.pollEvent(event)){

        switch (event.type){

        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape){
                window.close();
                break;
            }

            if (event.key.code == sf::Keyboard::Space){
                isInGame++;
                break;
            }

            if (event.key.code == sf::Keyboard::P){
                shoot = 1;
            }
        }

        }
       // bgMusic.play();

        //Clear the screen
        window.clear();

        //Draw the background images to the screen
       if (isInGame == 1){
        window.draw(bg);
        window.draw(ogre.getSprite());

        for (int i = 0;i<100;i++){
            ogre.getSprite().move(ogre.getSpeed(),0);
        }
        if (shoot == 1){
            window.draw(test);
            if (test.getPosition().x > 0){
                test.move(-2,0);
            }
            else {
                test.setPosition(1920,1000);
            }

        }
        }


        else {
            window.draw(menubg);
            if (isInGame = 2){
                isInGame = 0;
            }
            //music.play();
        }

        window.display();

    }

}


