#include "zinc.h"
#include "Zwindow.h"

int main()
{
  zclear();
  Zwindow z(5,5,70,14);
  z.set_label("ZORK");
  z.set_fill_char('\'');
  Zwindow zz(8,8,70,14);
  zz.set_label("GNU Calculatron mark VII");

  z.update();
  zz.update();
  zmove(0,24);
  std::cout << std::endl;
  return 0;
}
