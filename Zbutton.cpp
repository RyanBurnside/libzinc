#include "Zbutton.h"

Zbutton::Zbutton(int x, int y, int width) : 
  Zwidget(x, y, width, 1)
{
   // blank for now. 
   // No extra member variables beyond what is already made in base class
}

void Zbutton::update()
{
  Zwidget::update(); // call base class' drawing (rectangle)
  std::string sliced = label.substr(0, width -2); // Make the label fit
  std::string pad((width-2) - sliced.length(), ' ');
  sliced = '[' + sliced;
  sliced += pad;
  sliced += ']'; 
  zmove_put(x, y, sliced); // draw the label on the border
}
