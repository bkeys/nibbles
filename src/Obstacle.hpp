#pragma once

#include "Element.hpp"
#include "Snake.hpp"

class Item : public Element {

public:
  Item() {rotation = rand() % 360;};
  void draw() {
    glColor3ub(0, 255, 0);
    glPushMatrix();
    glTranslatef(x, y, -y);
    glRotatef(rotation, 0, 1, 0);
    glutSolidTeapot(.7);
    glPopMatrix();
  }

private:
  float rotation;

};

class Obstacle : public Element {

public:
  Obstacle();
  void draw(void);
  std::list<Item> item;
  std::list<Item>::iterator iter;
};
