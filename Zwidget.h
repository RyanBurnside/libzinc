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
  virtual void get_position(int &holder_x, int &holder_y);
  virtual void set_size(int width, int height);
  virtual void get_size(int &holder_width, int &holder_height);
  virtual void set_label(std::string l);
  virtual std::string get_label();
  virtual void draw();
  virtual void update();  
};

#endif
