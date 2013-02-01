#include "zinc.h"
#include "Zwindow.h"

int main()
{
  zclear();

  Zwindow z(5,5,70,14);
  z.set_label("Sample Window Titlebar");

  Zwindow zz(8,8,70,14);
  zz.set_label("Sample Window Titlebar 2");

  z.update();
  zz.update();
  zmove(0,24);
  std::cout << std::endl;
  return 0;
}
