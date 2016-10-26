#include "mymouse.h"
#include "SFML/Window.hpp"


    MyMouse::MyMouse(const sf::Window& _window, int mouse_width, int mouse_height) :
    window(_window)
    {
        //initialize box
        mouse_box.width = mouse_width;
        mouse_box.height = mouse_height;
    }

    sf::Vector2i getPosition(const sf::Window &relativeTo){
        return sf::Mouse::getPosition(relativeTo);
    }

    //WRAP THE REST OF sf::Mouse FUNCTIONS
    bool MyMouse::intersects(const sf::FloatRect& other_box){

        mouse_box.left =  sf::Mouse::getPosition(window).x;
        mouse_box.top =  sf::Mouse::getPosition(window).y;

        return mouse_box.intersects(other_box);

    }



