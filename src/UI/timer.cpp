#include <SFML/Graphics.hpp>
#include "timer.hpp"


Timer::Timer() : levelNumber(0)
{
    totalTime = timers[levelNumber].asSeconds();
}

void Timer::loadTimer(sf::RenderWindow& window,int level)
{
    clock.restart();
    levelNumber = level;

    totalTime = timers[levelNumber].asSeconds();
    
    sf::Vector2f viewSize = window.getView().getSize();
    sf::Vector2f viewCenter = window.getView().getCenter();

    float posx = viewCenter.x - viewCenter.x/2.f;
    float posy = viewCenter.y + viewSize.y/2.f - 20.f;

    rect = sf::FloatRect({posx, posy}, {viewSize.x, 20.f}); // rect size based on window mode

    bar.setPosition({rect.position.x, rect.position.y});
    bar.setSize({rect.size.x, rect.size.y});

    bar.setFillColor(sf::Color::Red);
}

void Timer::update(sf::RenderWindow& window)
{
    float elapsed = clock.getElapsedTime().asSeconds();
    float remainingRatio = std::max(0.f , 1 - (elapsed / totalTime));

    sf::Vector2f viewSize = window.getView().getSize();
    sf::Vector2f viewCenter = window.getView().getCenter();

    float posx = viewCenter.x - viewCenter.x;
    float posy = viewCenter.y + viewSize.y/2.f - 20.f;

    rect = sf::FloatRect({posx, posy}, {viewSize.x, 20.f}); // rect size based on window mode

    bar.setPosition({rect.position.x, rect.position.y});
    bar.setSize({rect.size.x * remainingRatio, rect.size.y});
}

void Timer::render(sf::RenderWindow& window)
{
    window.draw(bar);
}

void Timer::reset()
{
    clock.restart();
    bar.setSize({rect.size.x, rect.size.y});
}

bool Timer::isTimeUp()
{
    return clock.getElapsedTime().asSeconds() >= totalTime;
}

void Timer::pause()
{
    clock.stop();
}

void Timer::unpause()
{
    clock.start();
}
