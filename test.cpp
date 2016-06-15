#include "sprite2.cpp"
#include <SFML/Window.hpp>

int window_x=1000;
int window_y=600;

sf::Event event;
sf::RenderWindow window(sf::VideoMode(window_x, window_y), "YAY");

Sprite2 bert= Sprite2();
sf::Texture face;

//bert.texture.loadFromFile("BertFace.png");


int main()
{
  //shape.setFillColor(sf::Color::Red);//(150, 50, 200));
  face.loadFromFile("BertFace.png");
  bert.setTexture(face);
  sf::FloatRect bounds=bert.getGlobalBounds();
  bert.setPosition(window_x/2-bounds.width/2, window_y/2-bounds.height/2);

  while(window.isOpen())
  {
    event = sf::Event();


    while(window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
        {
          window.close();
        }

        if(event.type==sf::Event::KeyPressed)
        {
          if(event.key.code==sf::Keyboard::Left)
          {
            bert.move(-8, 0);
          }
          if(event.key.code==sf::Keyboard::Up)
          {
            bert.move(0, -8);
          }
          if(event.key.code==sf::Keyboard::Right)
          {
            bert.move(8, 0);
          }
          if(event.key.code==sf::Keyboard::Down)
          {
            bert.move(0, 8);
          }
        }

    }
    window.clear(sf::Color(0,0,0,255));


    window.draw(bert);
    window.display();
  }
  return 0;
};
