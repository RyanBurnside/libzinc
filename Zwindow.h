#ifndef ZWINDOW_H
#define ZWINDOW_H
#include "Zwidget.h"

class Zwindow : public Zwidget // Zwindow extends Zwidget
{
public:
  Zwindow(int x, int y, int width, int height);
  void update(); // override base class update for special drawing addition
};

#endif
