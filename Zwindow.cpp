#include "Zwindow.h"
#include "Zwidget.h"

Zwindow::Zwindow(int x, int y, int width, int height) :
  Zwidget(x, y, width, height)
{
  // Mandate all windows must be atleast 3 x 3
  // This prevents naughties with border and title handeling
  if(width < 3)
    this->width = 3;
  if(height < 3)
  this->height = 3;
  this->Zwidget::set_size(width, height); // Readjust the base class
}

void Zwindow::update()
{
  Zwidget::update(); // call base class' drawing (rectangle)
  std::string sliced = label.substr(0, width - 2); // Make the label fit
  std::string pad(width - sliced.length() - 1, '=');
  zmove_put(x, y, '=');
  zmove_put(x + 1, y, sliced + pad); // draw the label on the border
}
