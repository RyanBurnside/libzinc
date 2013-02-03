#include "zinc.h"
#include "Zwidget.h"
#include "Zwindow.h"
#include "Zbutton.h"

int main()
{
  zclear();
  Zwindow z(5, 5, 70, 14);
  z.set_label("ZORK");
  Zbutton b(57, 17, 8);
  Zbutton c(66, 17, 8);
  b.set_label("OK");
  c.set_label("CANCEL");

  z.update();
  b.update();
  c.update();
  zmove(0, 24);
  std::cout << std::endl;
  return 0;
}
