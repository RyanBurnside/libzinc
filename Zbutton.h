#ifndef ZBUTTON_H
#define ZBUTTON_H
#include "Zwidget.h"

class Zbutton : public Zwidget // Zbutton extends Zwidget
{
public:
  Zbutton(int x, int y, int width);
  virtual void update(); // override base class update for special drawing addition
};

#endif
