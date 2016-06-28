#include<SFML/Graphics.hpp>

class Sprite2: public sf::Sprite
{
public:
  int x_pos, y_pos;
  int x_vel, y_vel;
  double x_scale, y_scale;
  sf::Texture texture;
  sf::FloatRect scale;

  Sprite2()
  {
    x_scale=.2;
    y_scale=.2;
    setScale(x_scale, y_scale);
    scale = getGlobalBounds();
    x_pos = y_pos = 0;
    x_vel = y_vel = 0;

    //texture.loadFromFile("BertFace.png");
    //setTexture(texture);
  }
}
;
