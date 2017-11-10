#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({750, 600}), "My Name");

    window.clear();

    sf::RectangleShape p0;
    p0.setSize({800, 600});
    p0.setPosition({0, 0});
    p0.setFillColor(sf::Color(255, 218, 185));
    window.draw(p0);

    sf::RectangleShape p1;
    p1.setSize({50, 250});
    p1.setPosition({50, 150});
    p1.setFillColor(sf::Color(128, 0, 0));
    window.draw(p1);

    sf::RectangleShape p2;
    p2.setSize({150, 50});
    p2.setPosition({50, 150});
    p2.setFillColor(sf::Color(128, 0, 0));
    window.draw(p2);

    sf::RectangleShape p3;
    p3.setSize({200, 50});
    p3.setPosition({50, 350});
    p3.setFillColor(sf::Color(128, 0, 0));
    window.draw(p3);

    sf::RectangleShape p4;
    p4.setSize({50, 150});
    p4.setPosition({200, 250});
    p4.setFillColor(sf::Color(128, 0, 0));
    window.draw(p4);

    sf::RectangleShape p5;
    p5.setSize({100, 50});
    p5.setPosition({150, 250});
    p5.setFillColor(sf::Color(128, 0, 0));
    window.draw(p5);

    sf::RectangleShape p6;
    p6.setSize({50, 280});
    p6.setRotation(345);
    p6.setPosition({250, 150});
    p6.setFillColor(sf::Color(255, 0, 0));
    window.draw(p6);

    sf::RectangleShape p7;
    p7.setSize({50, 300});
    p7.setRotation(15);
    p7.setPosition({420, 120});
    p7.setFillColor(sf::Color(255, 0, 0));
    window.draw(p7);

    sf::RectangleShape p8;
    p8.setSize({50, 280});
    p8.setRotation(345);
    p8.setPosition({485, 150});
    p8.setFillColor(sf::Color(139, 0, 0));
    window.draw(p8);

    sf::RectangleShape p9;
    p9.setSize({50, 300});
    p9.setRotation(15);
    p9.setPosition({655, 120});
    p9.setFillColor(sf::Color(139, 0, 0));
    window.draw(p9);

    sf::RectangleShape p10;
    p10.setSize({800, 100});
    p10.setPosition({50, 50});
    p10.setFillColor(sf::Color(255, 218, 185));
    window.draw(p10);

    sf::RectangleShape p11;
    p11.setSize({800, 100});
    p11.setPosition({250, 400});
    p11.setFillColor(sf::Color(255, 218, 185));
    window.draw(p11);

    window.display();

    sf::sleep(sf::seconds(5));
}