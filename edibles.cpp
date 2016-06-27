#include<SFML/Graphics.hpp>

class Edibles: public sf::Sprite
{
public:
  int x_pos, y_pos;

  sf::Texture texture;
  sf::FloatRect scale;

  Edibles()
  {
    setScale(.1, .1);
    scale = getGlobalBounds();
    x_pos = y_pos = 0;

    //texture.loadFromFile("BertFace.png");
    //setTexture(texture);
  }
}
;
