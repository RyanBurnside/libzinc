#include "Zwidget.h"

Zwidget::Zwidget(int x, int y, int width, int height)
{
  this->x = x;
  this->y = y;
  this->width = width;
  this->height = height;
}

Zwidget::~Zwidget(){};

void Zwidget::set_position(int x, int y)
{
  this->x = x;
  this->y = y;
}
void Zwidget::set_size(int width, int height)
{
  this->x = x;
  this->y = y;
}

void Zwidget::draw()
{
  zdraw_block(x, y, width, height, '.', '+', '|', '-');
};

void Zwidget::update()
{
  draw();
}
