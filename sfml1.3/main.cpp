#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "House");

    window.clear();

    sf::RectangleShape background;
    background.setSize({800, 600});
    background.setPosition({0, 0});
    background.setFillColor(sf::Color(175, 238, 238));
    window.draw(background);

    sf::RectangleShape walls;
    walls.setSize({400, 200});
    walls.setPosition({200, 350});
    walls.setFillColor(sf::Color(139, 69, 19));
    window.draw(walls);

    sf::RectangleShape door;
    door.setSize({75, 125});
    door.setPosition({250, 425});
    door.setFillColor(sf::Color(105, 105, 105));
    window.draw(door);

    sf::ConvexShape roof;
    roof.setFillColor(sf::Color(128, 0, 0));
    roof.setPosition({400, 250});
    roof.setPointCount(4);
    roof.setPoint(0, {-100, 0});
    roof.setPoint(1, {+100, 0});
    roof.setPoint(2, {+250, 100});
    roof.setPoint(3, {-250, 100});
    window.draw(roof);

    sf::RectangleShape chimney;
    chimney.setSize({35, 75});
    chimney.setPosition({450, 225});
    chimney.setFillColor(sf::Color(105, 105, 105));
    window.draw(chimney);

    sf::CircleShape smoke1(18);
    smoke1.setPosition({464, 165});
    smoke1.setFillColor(sf::Color(169, 169, 169));
    window.draw(smoke1);

    sf::RectangleShape chimney2;
    chimney2.setSize({65, 30});
    chimney2.setPosition({435, 195});
    chimney2.setFillColor(sf::Color(105, 105, 105));
    window.draw(chimney2);

    sf::CircleShape smoke2(22);
    smoke2.setPosition({485, 135});
    smoke2.setFillColor(sf::Color(169, 169, 169));
    window.draw(smoke2);

    sf::CircleShape smoke3(25);
    smoke3.setPosition({495, 95});
    smoke3.setFillColor(sf::Color(169, 169, 169));
    window.draw(smoke3);

    sf::CircleShape smoke4(30);
    smoke4.setPosition({520, 55});
    smoke4.setFillColor(sf::Color(169, 169, 169));
    window.draw(smoke4);

    window.display();

    sf::sleep(sf::seconds(5));
}