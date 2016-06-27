
#include <SFML/Window.hpp>
#include "test.h"

/*int window_x=1000;
int window_y=600;
int maryexist=0;

sf::Event event;
sf::RenderWindow window(sf::VideoMode(window_x, window_y), "YAY");

Sprite2 bert= Sprite2();
Sprite2 mary= Sprite2();
sf::Texture bertface;
sf::Texture maryface; */

//bert.texture.loadFromFile("BertFace.png");


void make_bert()
{
    bert= Sprite2();
    bertface.loadFromFile("BertFace.png");
    bert.setTexture(bertface);
    sf::FloatRect boundsB=bert.getGlobalBounds();
    bert.setPosition(window_x/2-boundsB.width/2, window_y/2-boundsB.height/2);
}
void make_mary()
{
  mary= Edibles();
  maryface.loadFromFile("maryface.png");

  mary.setTexture(maryface);

}
void move_bert()
{
  bert.move(bert.x_vel, bert.y_vel);
}


void key_pressed_moves()
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
void key_released_moves()
  {
          bert.x_vel=0; bert.y_vel=0;
  }
void eatMary()
  {
      if (bert.getGlobalBounds().intersects(mary.getGlobalBounds()))
      {
          maryexist=1;
        }
  }
void checkOutOfBounds()
{
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

void draw_all()
{
    window.clear(sf::Color(0,0,0,255));


      window.draw(bert);
      if (!maryexist)
      {
        window.draw(mary);
      }
      window.display();

}
