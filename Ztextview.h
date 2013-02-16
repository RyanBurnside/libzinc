#ifndef ZTEXTVIEW_H
#define ZTEXTVIEW_H
#include "Zwidget.h"
#include <vector>

class Ztextview : public Zwidget // Ztextview extends Zwidget
{
protected:
  unsigned int marker; // The first line of the text in the display box
  std::string text;
  std::vector<std::string> lines;
  unsigned int top_line;
  void add_word(const std::string &word);
  
public:
  Ztextview(int x, int y, int width, int height);
  void set_text(const std::string &str);
  void set_top_line(unsigned int top);
  unsigned int get_top_line();
  unsigned int get_num_lines();
  virtual void update(); // override base class update for special drawing addition
};

#endif
