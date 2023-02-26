/*
** EPITECH PROJECT, 2023
** Hakathon
** File description:
** Menu
*/

#include "Menu.hpp"

Menu::Menu(float width, float height)
{
    if (!font.loadFromFile("assets/font/gameplay.ttf"))
    {
        std::cout << "Error: Font not found" << std::endl;
    }
    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Play");
    menu[0].setCharacterSize(70);
    menu[0].setPosition(sf::Vector2f(width / 2, height / (Max_main_menu + 1) * 1));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Options");
    menu[1].setCharacterSize(70);
    menu[1].setPosition(sf::Vector2f(width / 2, height / (Max_main_menu + 1) * 2));

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Credits");
    menu[2].setCharacterSize(70);
    menu[2].setPosition(sf::Vector2f(width / 2, height / (Max_main_menu + 1) * 3));

    menu[3].setFont(font);
    menu[3].setColor(sf::Color::White);
    menu[3].setString("Exit");
    menu[3].setCharacterSize(70);
    menu[3].setPosition(sf::Vector2f(width / 2, height / (Max_main_menu + 1) * 4));

    SelectedItemIndex = -1;
}

Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < Max_main_menu; i++)
    {
        window.draw(menu[i]);
    }
}

void Menu::MoveUp()
{
    if (SelectedItemIndex - 1 >= 0)
    {
        menu[SelectedItemIndex].setColor(sf::Color::White);
        SelectedItemIndex--;
        if(SelectedItemIndex == -1)
            SelectedItemIndex = 2;
        menu[SelectedItemIndex].setColor(sf::Color::Red);
    }
}

void Menu::MoveDown()
{
    if (SelectedItemIndex + 1 < Max_main_menu)
    {
        menu[SelectedItemIndex].setColor(sf::Color::White);
        SelectedItemIndex++;
        if(SelectedItemIndex == 4)
            SelectedItemIndex = 0;
        menu[SelectedItemIndex].setColor(sf::Color::Red);
    }
}

int Menu::GetPressedItem()
{
    return SelectedItemIndex;
}