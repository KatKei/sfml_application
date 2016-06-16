#include "sprite2.cpp"
#include <SFML/Window.hpp>

int window_x=1000;
int window_y=600;
int maryexist=0;

sf::Event event;
sf::RenderWindow window(sf::VideoMode(window_x, window_y), "YAY");

Sprite2 bert= Sprite2();
Sprite2 mary= Sprite2();
sf::Texture bertface;
sf::Texture maryface;

//bert.texture.loadFromFile("BertFace.png");


int main()
{
  //shape.setFillColor(sf::Color::Red);//(150, 50, 200));
  bertface.loadFromFile("BertFace.png");
  maryface.loadFromFile("maryface.png");
  bert.setTexture(bertface);
  mary.setTexture(maryface);
  mary.setPosition(30, 150); //make random later
  sf::FloatRect boundsB=bert.getGlobalBounds();
  bert.setPosition(window_x/2-boundsB.width/2, window_y/2-boundsB.height/2);

  while(window.isOpen())
  {
    event = sf::Event();

      bert.move(bert.x_vel, bert.y_vel);
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
            bert.x_vel=-1; bert.y_vel=0;
          }
          if(event.key.code==sf::Keyboard::Up)
          {
              bert.y_vel=-1; bert.x_vel=0;
          }
          if(event.key.code==sf::Keyboard::Right)
          {
              bert.x_vel=1; bert.y_vel=0;
          }
          if(event.key.code==sf::Keyboard::Down)
          {
              bert.y_vel=1; bert.x_vel=0;
          }
        }
        if (bert.getGlobalBounds().intersects(mary.getGlobalBounds()))
        {
          maryexist=1;
        }
        if (bert.getPosition().x > window_x)
        {
          bert.setPosition(0, bert.getPosition().y);
        }
        if (bert.getPosition().x < 0)
        {
          bert.setPosition(window_x, bert.getPosition().y);
        }
        if (bert.getPosition().y > window_y)
        {
          bert.setPosition(bert.getPosition().x, 0);
        }
        if (bert.getPosition().y < 0)
        {
          bert.setPosition(bert.getPosition().x, window_y);
        }

    }
    window.clear(sf::Color(0,0,0,255));


    window.draw(bert);
    if (maryexist==0)
    {
      window.draw(mary);
    }
    window.display();
  }
  return 0;
};
