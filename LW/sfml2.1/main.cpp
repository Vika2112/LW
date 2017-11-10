#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;
    constexpr float BALL_SIZE = 40;

    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Moving Ball");
    sf::Clock clock;
    sf::Clock clock2;

    sf::CircleShape shape(BALL_SIZE);
    shape.setPosition({10, 350});
    shape.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    float speedX = 100.f;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        const float dt = clock.restart().asSeconds();
        const float time = clock2.getElapsedTime().asSeconds();

        sf::Vector2f position = shape.getPosition();
        position.x += speedX * dt;
        position.y = 350 + 80.f * std::sin(float(2 * M_PI) * time / 2);

        if ((position.x + 2 * BALL_SIZE >= WINDOW_WIDTH) && (speedX > 0))
        {
            speedX = -speedX;
        }
        if ((position.x < 0) && (speedX < 0))
        {
            speedX = -speedX;
        }

        shape.setPosition(position);

        window.clear();
        window.draw(shape);
        window.display();
    }
}