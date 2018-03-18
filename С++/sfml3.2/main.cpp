#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <cmath>
#include <iostream>

struct Eye
{
    sf::ConvexShape ellipse;
    sf::ConvexShape pupil;
    sf::Vector2f position;
    float rotation = 0;
};

// Переводит полярные координаты в декартовы
sf::Vector2f toEuclidean(float radiusX, float radiusY, float angle)
{
    return {
        radiusX * std::cos(angle),
        radiusY * std::sin(angle)};
}

// Переводит радианы в градусы
float toDegrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

// Обновляет состояние глаза
void updateEye(Eye &eye)
{
    const sf::Vector2f PupilOffset = toEuclidean(20, 40, eye.rotation);
    eye.pupil.setPosition(eye.position + PupilOffset);
    eye.ellipse.setPosition(eye.position);
}

// Инициализирует зрачок
void initPupil(Eye &eye)
{
    eye.pupil.setFillColor(sf::Color(0, 0, 0));

    constexpr int pointCount = 200;
    sf::Vector2f ellipseRadius = {20.f, 30.f};
    eye.pupil.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        sf::Vector2f point = {
            ellipseRadius.x * std::cos(angle),
            ellipseRadius.y * std::sin(angle)};
        eye.pupil.setPoint(pointNo, point);
    }
}

// Инициализирует глаз
void initEye(Eye &eye, const float x, const float y)
{
    eye.position = {x, y};

    eye.ellipse.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));

    constexpr int pointCount = 200;
    sf::Vector2f ellipseRadius = {57.f, 130.f};
    eye.ellipse.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        sf::Vector2f point = {
            ellipseRadius.x * std::cos(angle),
            ellipseRadius.y * std::sin(angle)};
        eye.ellipse.setPoint(pointNo, point);
    }

    initPupil(eye);
    updateEye(eye);
}

// Обрабатывает событие MouseMove, обновляя позицию мыши
void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    std::cout << "mouse x=" << event.x << ", y=" << event.y << std::endl;
    mousePosition = {float(event.x), float(event.y)};
}

// Опрашивает и обрабатывает доступные события в цикле
void pollEvents(sf::RenderWindow &window, sf::Vector2f &mousePosition)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseMoved:
            onMouseMove(event.mouseMove, mousePosition);
            break;
        default:
            break;
        }
    }
}

// Обновляет зрачки
void update(const sf::Vector2f &mousePosition, Eye &LeftEye, Eye &RightEye)
{
    sf::Vector2f delta = mousePosition - LeftEye.position;
    LeftEye.rotation = atan2(delta.y, delta.x);
    updateEye(LeftEye);

    delta = mousePosition - RightEye.position;
    RightEye.rotation = atan2(delta.y, delta.x);
    updateEye(RightEye);
}

// Рисует и выводит один кадр
void redrawFrame(sf::RenderWindow &window, Eye &LeftEye, Eye &RightEye)
{
    window.clear();
    window.draw(LeftEye.ellipse);
    window.draw(LeftEye.pupil);
    window.draw(RightEye.ellipse);
    window.draw(RightEye.pupil);
    window.display();
}

//  Рисует в окне глаза, у которых зрачки поворачиваются за курсором мыши

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Looking eyes", sf::Style::Default, settings);

    Eye LeftEye;
    Eye RightEye;

    sf::Vector2f mousePosition;

    initEye(LeftEye, 325, 300);
    initEye(RightEye, 445, 300);
    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        update(mousePosition, LeftEye, RightEye);
        redrawFrame(window, LeftEye, RightEye);
    }
}