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
  std::string sliced = label.substr(0, width -6); // Make the label fit
  std::string pad((width-6) - sliced.length(), '=');
  zmove_put(x, y, '=');
  zmove_put(x+1, y, sliced + pad); // draw the label on the border
  zmove_put(x+width -5, y, "[-|X]"); // add controll "buttons"
}
