
#include <QApplication>
#include <iostream>

#include <mymouse.h>
#include <ogre.h>
#include <button.h>
#include <gamestatecontroller.h>

#include <time.h>
#include <ctime>


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

    int newTower = 0;
    int upgradeTower = 0;
    int TowerOptions = 0;
    int gameEnded = 0;

    int ist = 0;



    Button matrix[264];
    Button popups[5];
    Button popups2[2];

    Button b0;
    b0.Pop(559,0,132,100);

    Button b1;
    b1.Pop(853,0,168,100);
    Button b2;
    b2.Pop(1153,0,132,100);

    Button b3;
    b3.Pop(625,0,264,100);
    Button b4;
    b4.Pop(1087,0,66,100);

    popups[0] = b0;
    popups[1] = b1;
    popups[2] = b2;
    popups2[0] = b3;
    popups2[1] = b4;

    int count = 0;
    int tempTower = 0;

    int matriz[12][22];
    for (int i = 0; i < 12; i++){

     for (int j = 0; j < 22; j++){
         Button button;
         button.Buttons(229+(66*j),143+(66*i),sf::Color::Black);
         //matriz[j][i] = 0;
         //button.i = i;
         //button.j = j;
        //button.NewButton(3);

         matrix[count] = button;
         count ++;
     }
    }

    /**for (int i = 0; i < 12; i++){
        for (int j = 0; j<22; j++){

            cout << matriz[i][j];

        }
        cout << endl;
    }
    **/



    //Define int for simple handling of sprite issues
    int isInGame = 0;
    int shoot = 0;

    //Test for Ogre movement and stuff
   // Ogre ogre = Ogre::Ogre(0.5,2.0,2.0,2.0) ;

    //Create the main window
    sf::RenderWindow window (sf::VideoMode(1920,1080),"GeneticKingdom",sf::Style::Fullscreen);

    //Load Background Image

    sf::Texture menu;
    if (!menu.loadFromFile("C:/Users/jpvin/Documents/SpriteResources/menu_bg.jpg")){

        return EXIT_FAILURE;
    }

    sf::Texture tower;
    if(!tower.loadFromFile("C:/Users/jpvin/Documents/SpriteResources/TowerSprite.png")){

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

    sf::Texture end;
    if (!end.loadFromFile("C:/Users/jpvin/Documents/SpriteResources/PopUpEndGame.png")){

        return EXIT_FAILURE;
    }
    sf::Sprite EndGame;
    EndGame.setTexture(end);
    EndGame.setPosition(sf::Vector2f(450,0));

    sf::Texture opt;
    if (!opt.loadFromFile("C:/Users/jpvin/Documents/SpriteResources/TowerPopUp.png")){

        return EXIT_FAILURE;
    }

    sf::Sprite Options;
    Options.setTexture(opt);
    Options.setPosition(sf::Vector2f(450,-300));

    sf::Texture New;
    if (!New.loadFromFile("C:/Users/jpvin/Documents/SpriteResources/TowerPopUpNew.png")){

        return EXIT_FAILURE;
    }

    sf::Sprite newtow;
    newtow.setTexture(New);
    newtow.setPosition(sf::Vector2f(450,-300));

    sf::Texture Upgra;
    if (!Upgra.loadFromFile("C:/Users/jpvin/Documents/SpriteResources/TowerPopUpUpgrade.png")){

        return EXIT_FAILURE;
    }

    sf::Sprite upgrade;
    upgrade.setTexture(Upgra);
    upgrade.setPosition(sf::Vector2f(450,-300));

    sf::Font font;
    if(!font.loadFromFile("C:/Users/jpvin/Documents/SpriteResources/Viking.ttf")){

        return EXIT_FAILURE;
    }

    sf::Text timer;
    timer.setColor(sf::Color::Red);
    timer.setFont(font);
    timer.setCharacterSize(48);
    timer.setStyle(sf::Text::Bold|sf::Text::Italic);
    timer.setString("Hello World");
    timer.setPosition(sf::Vector2f(100,3));

    int seconds = 30;



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



        sf::RectangleShape node;
        node. setFillColor(sf::Color::Blue);
        node.setPosition(229,143);
        node.setSize(sf::Vector2f(66,66));

        Button btton;
        btton.Buttons(229,143,sf::Color::Black);




    //Create background sprite
    sf::Sprite bg;
    bg.setTexture(background);

    GameStateController game;
    game.init();

    //Start Game Loop
    while (window.isOpen()){

        //sf::Time elapsed = sf::Clock.restart();

        //seconds -= elapsed.asSeconds();



        //Handle events
        sf::Event event;
        while (window.pollEvent(event)){

        switch (event.type){

        case sf::Event::KeyPressed:
        {if (event.key.code == sf::Keyboard::Escape){
                window.close();
                break;
            }

            if (event.key.code == sf::Keyboard::Space){
                isInGame++;
                break;
            }

            if (event.key.code == sf::Keyboard::P){
                newTower  = newTower*0;

            }
        }

        case sf::Event::MouseButtonPressed: {

            sf::Vector2i pos = sf::Mouse::getPosition();

            if (game.getNewTower()){
                //window.draw(newtow);
                cout <<"Aqui estoy" << endl;
               for (int i = 0; i < 3; i++){
                   Button buton = popups[i];
                   if (buton.checkClick(pos)){
                       cout << "Entre" << endl;
                       matrix[tempTower].hasTower = true;

                       newTower = newTower*0;
                       if (i == 0){
                       cout << "Created new Archer" << endl;
                       game.setNewTower(false);
                       matrix[tempTower].setType(0);
                       newTower = 0;
                       }
                       if (i==1){
                           cout << "Created new Warlock" << endl;
                           game.setNewTower(false);
                           matrix[tempTower].setType(1);
                           newTower = 0;

                       }

                       if (i==2){
                           cout << "Created new Sniper" << endl;
                           game.setNewTower(false);
                           matrix[tempTower].setType(2);
                           newTower = 0;

                       }





                   }


               }

               game.setNewTower(false);
               newTower ++;





            }

            if (TowerOptions == 1){
                for (int i = 0; i<2;i++){
                    Button temp = popups2[i];
                    if (temp.checkClick(pos)){
                        if (i == 0){
                            cout << "upgrading tower" << endl;
                            int t = matrix[tempTower].getLevel();
                            t = t+1;
                            if (t < 3){
                                matrix[tempTower].setLevel(t);
                                cout << "Upgraded tower to level " << t << endl;
                                upgradeTower = 1;
                            }

                            else {
                                cout << "tower is at maximum level " << endl;
                            }
                            TowerOptions = 0;

                        }
                        else {
                            cout << "will sell the tower" << endl;
                            TowerOptions = 0;
                        }
                    }
                }
                TowerOptions = 0;
            }

            if (  upgradeTower == 0  && gameEnded == 0 && !game.getNewTower()){
            for (int i = 0; i < 264; i++){

               Button buton = matrix[i];
               int tem = i;
            if (buton.checkClick(pos) ){
                tempTower = tem;
                cout << tempTower <<endl;
                cout << "Button was clicked " << "Y pos:" << buton.getPosition().y << " X pos:" << buton.getPosition().x<< endl;
                //matrix[i].hasTower = true;
                if (!matrix[i].hasTower){
                    matrix[i].getRect().setFillColor(sf::Color::Green);
                    game.setNewTower(true);
                    window.draw(matrix[i].getRect());

                }

                if (matrix[i].hasTower){
                    TowerOptions = 1;
                }


            }

            }

        }


        }
        }
       // bgMusic.play();

        //Clear the screen
        window.clear();

        //Draw the background images to the screen
       if (isInGame == 1){

           window.draw(bg);


          for (int i = 0; i < 264; i++){
              if (matrix[i].hasTower){

                 // window.draw(matrix[i].getRect());
                  sf::Sprite temp;
                  temp.setTexture(tower);
                  temp.setPosition(matrix[i].getPosition());
                  window.draw(temp);


          }

       if (game.getNewTower()){

            window.draw(newtow);
        }

        if(upgradeTower == 1){
            window.draw(upgrade);
        }

        if (gameEnded == 1){
            window.draw(EndGame);
        }

        if (TowerOptions == 1){
            window.draw(Options);
        }

        window.draw(timer);


       // window.draw(ogre.getSprite());

       /** for (int i = 0;i<100;i++){
           // ogre.getSprite().move(ogre.getSpeed(),0);
        }**/

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


}



