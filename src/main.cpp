#include <SFML/Graphics.hpp>
using namespace sf; 

int main(){
    RenderWindow window(sf::VideoMode({200, 200}), "SFML Window.");
    CircleShape shape(100.f);
    shape.setFillColor(Color::Green);

    while (window.isOpen()){
        while (const std::optional event = window.pollEvent()){
            if (event->is<Event::Closed>())
                window.close();
        }

        window.clear(Color::White);
        window.draw(shape);
        window.display();
    }
}