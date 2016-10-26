#ifndef MYMOUSE_H
#define MYMOUSE_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>



class MyMouse
{
public:
    MyMouse(const sf::Window& _window, int mouse_width, int mouse_height);
    bool intersects(const sf::FloatRect& other_box);


private:
   const sf::Window& window;
   sf::FloatRect mouse_box;
};

#endif // MYMOUSE_H
