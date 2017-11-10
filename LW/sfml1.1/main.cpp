#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({240, 570}), "Traffic light");

    window.clear();

    sf::RectangleShape rectangle;

    rectangle.setSize({200, 530});
    rectangle.setPosition({20, 15});
    rectangle.setFillColor(sf::Color(128, 128, 128));
    window.draw(rectangle);

    sf::CircleShape circle1(75);
    circle1.setPosition({45, 25});
    circle1.setFillColor(sf::Color(0, 255, 0));
    window.draw(circle1);

    sf::CircleShape circle2(75);
    circle2.setPosition({45, 200});
    circle2.setFillColor(sf::Color(255, 255, 0));
    window.draw(circle2);

    sf::CircleShape circle3(75);
    circle3.setPosition({45, 375});
    circle3.setFillColor(sf::Color(255, 0, 0));
    window.draw(circle3);

    window.display();

    sf::sleep(sf::seconds(5));
}