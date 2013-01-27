#ifndef ZWIDGET_H
#define ZWIDGET_H
#include <string>

class Zwidget
{
protected:
  int x, y, width, height;
  std::string label;
  
public:
  virtual void set_position(int x, int y);
  virtual void set_size(int width, int height);
  virtual void draw();
};

#endif
