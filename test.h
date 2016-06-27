#include "sprite2.cpp"
#include "edibles.cpp"
#include <SFML/Window.hpp>

int window_x=1000;
int window_y=600;
int maryexist=0;

sf::Event event;
sf::RenderWindow window(sf::VideoMode(window_x, window_y), "YAY");

Sprite2 bert;
Edibles mary;
sf::Texture bertface;
sf::Texture maryface;

//bert.texture.loadFromFile("BertFace.png");

void make_bert();
void make_mary();
void move_bert();
void key_pressed_moves();
void key_released_moves();
void checkOutOfBounds();
void eatMary();
void draw_all();


int main()
{

  make_bert();
  make_mary();
  srand(time(NULL));
   //rand() % window_x , rand() % window_y
  mary.setPosition(rand() % window_x, rand() % window_y); //make random later
  while(window.isOpen())
  {
    event = sf::Event();

    move_bert();
    checkOutOfBounds();

      //bert.move(bert.x_vel, bert.y_vel);
    while(window.pollEvent(event))
    {


        if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
        {
          window.close();
        }

        if(event.type==sf::Event::KeyPressed)
        {
          key_pressed_moves();
        }
        if(event.type==sf::Event::KeyReleased)
        {
          key_released_moves();
        }
    }
    eatMary();
    draw_all();
  }
  return 0;
}
;
