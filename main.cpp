#include "zinc.h"
#include "Zwidget.h"
#include "Zwindow.h"
#include "Zbutton.h"

int main()
{
  zclear();
  for(int i = 1; i < 5; ++i)
  {
    Zwindow z(i * 2, i * 2, 72, 16);
    std::string label = "Window ";
    label += char(i + 48);
    z.set_label(label);
    z.update();
  }

  zmove(0, 24);
  std::cout << std::endl;
  return 0;
}
