/*
** EPITECH PROJECT, 2023
** Hakathon
** File description:
** Menu
*/
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <string>
#define Max_main_menu 4

class Menu
{
    private:
        int SelectedItemIndex;
        sf::Font font;
        sf::Text menu[Max_main_menu];

    public:
        Menu(float width, float height);
        void draw(sf::RenderWindow &window);
        void MoveUp();
        void MoveDown();
        int GetPressedItem();
        ~Menu();
};


