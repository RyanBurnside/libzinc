#ifndef ZWINDOW_H
#define ZWINDOW_H
#include "Zwidget.h"

class Zbutton : public Zwidget // Zbutton extends Zwidget
{
public:
  Zbutton(int x, int y, int width);
  void update(); // override base class update for special drawing addition
};

#endif
