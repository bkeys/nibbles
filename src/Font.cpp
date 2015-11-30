#include "Font.hpp"

void Font::bitmap_output(int x, int y, const char *string, void *font) {
  int len, i;

  glRasterPos2f(x, y);
  len = static_cast<int>(strlen(string));
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(font, string[i]);
  }
}

