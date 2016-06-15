#include<SFML/Graphics.hpp>

class Sprite2: public sf::Sprite
{
public:
  int x_pos, y_pos;
  int x_vel, y_vel;
  sf::Texture texture;
  sf::FloatRect scale;

  Sprite2()
  {
    setScale(.2, .2);
    scale = getGlobalBounds();
    x_pos = y_pos = 0;
    x_vel = y_vel = 0;

    //texture.loadFromFile("BertFace.png");
    //setTexture(texture);
  }
}
;
