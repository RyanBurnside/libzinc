#include "Zwidget.h"

Zwidget::Zwidget(int x, int y, int width, int height)
{
  this->x = x;
  this->y = y;
  this->width = width;
  this->height = height;
  this->label = "";
  this->fill_char = ' ';
}

Zwidget::~Zwidget(){};

void Zwidget::set_position(int x, int y)
{
  this->x = x;
  this->y = y;
}

void Zwidget::get_position(int &x_holder, int &y_holder)
{
  x_holder = this->x;
  y_holder = this->y;
}

void Zwidget::set_size(int width, int height)
{
  this->x = x;
  this->y = y;
}

void Zwidget::get_size(int &width_holder, int &height_holder)
{
  width_holder = this->width;
  height_holder = this->height;
}

void Zwidget::set_label(std::string l)
{
  label = l;
}

std::string Zwidget::get_label()
{
  return label;
}

void Zwidget::set_fill_char(unsigned char c)
{
  fill_char = c;
}

unsigned char Zwidget::get_fill_char()
{
  return fill_char;
}

void Zwidget::draw()
{
  zdraw_block(x, y, width, height, fill_char, '+', '|', '-');
};

void Zwidget::update()
{
  draw();
}
