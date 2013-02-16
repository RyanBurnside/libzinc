#include "zinc.h"
#include "Zwidget.h"
#include "Zwindow.h"
#include "Ztextview.h"
int main(int argc, char* argv[])
{
  zclear();

  Zwindow w(1, 1, 80, 24);
  w.update();
  Ztextview t(3, 2, 24, 10);
  t.set_text(
    "Above the winda\n"
    "This\n"
    "is\n"
    "a\n"
    "very\n"
    "looooooooooooooooooooooooooooooooooooooooooooooooooong\n"
    "comment!\n"
    "BALLOCKS! below the winda");
  t.set_top_line(1);
  t.update();
  zmove(0, 24);
  std::cout << std::endl;
  return 0;
}
