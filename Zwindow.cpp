#include "Zwindow.h"

Zwindow::Zwindow(int x, int y, int width, int height) : 
  Zwidget(x, y, width, height)
  {
   // blank for now. 
   // No extra member variables beyond what is already made in base class
  }

void Zwindow::update()
{
  Zwidget::update(); // call base class' drawing (rectangle)
  zmove_put(x, y, label); // draw the label on the border
  zmove_put(x+width -6, y, "[-][x]"); // add controll "buttons"
}
