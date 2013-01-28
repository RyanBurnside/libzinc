#ifndef ZWIDGET_H
#define ZWIDGET_H
#include <string>
#include "zinc.h"

class Zwidget
{
protected:
  int x, y, width, height;
  std::string label;
  
public:
  Zwidget(int x, int y, int width, int height);
  virtual ~Zwidget();
  virtual void set_position(int x, int y);
  virtual void set_size(int width, int height);
  virtual void draw();
  virtual void update();  
};

#endif
