/*
** EPITECH PROJECT, 2023
** Hakathon
** File description:
** main
*/

#include "include/Menu.hpp";

void play_menu(sf::RenderWindow &Play)
{
    sf::Event event;

    while(Play.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                Play.close();
                break;
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                    case sf::Keyboard::Escape:
                        Play.close();
                        break;
                }
                break;
        }
    }
}

void option_menu(sf::RenderWindow &Option)
{
    sf::Event event;

    while(Option.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                Option.close();
                break;
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                    case sf::Keyboard::Escape:
                        Option.close();
                        break;
                }
                break;
        }
    }
}

void about_menu(sf::RenderWindow &About)
{
    sf::Event event;

    while(About.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                About.close();
                break;
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                    case sf::Keyboard::Escape:
                        About.close();
                        break;
                }
                break;
        }
    }
}

int main() 
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Hakathon");
    Menu menu(window.getSize().x, window.getSize().y);
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::KeyReleased:
                    switch (event.key.code)
                    {
                        case sf::Keyboard::Up:
                            menu.MoveUp();
                            break;
                        case sf::Keyboard::Down:
                            menu.MoveDown();
                            break;
                        case sf::Keyboard::Return:
                            sf::RenderWindow Play(sf::VideoMode(1920, 1080), "Hakathon");
                            sf::RenderWindow Option(sf::VideoMode(1920, 1080), "Options");
                            sf::RenderWindow About(sf::VideoMode(1920, 1080), "Abouts");
                            switch (menu.GetPressedItem())
                            {
                                case 0:
                                    play_menu(Play);
                                    std::cout << "Play button has been pressed" << std::endl;
                                    break;
                                case 1:
                                    option_menu(Option);
                                    std::cout << "Options button has been pressed" << std::endl;
                                    break;
                                case 2:
                                    about_menu(About);
                                    std::cout << "Credits button has been pressed" << std::endl;
                                    break;
                                case 3:
                                    window.close();
                                    break;
                            }
                            break;
                    }
                    break;
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }
        window.clear();
        menu.draw(window);
        window.display();
    }
    return 0;
}