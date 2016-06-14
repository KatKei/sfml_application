#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int window_x=1000;
int window_y=600;

sf::Event event;
sf::RenderWindow window(sf::VideoMode(window_x, window_y), "YAY");

int main()
{
  while(window.isOpen())
  {
    event = sf::Event();

    while(window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        {
          window.close();
        }
    }
    window.clear(sf::Color(0,0,0,255));
    window.display();
  }
}
