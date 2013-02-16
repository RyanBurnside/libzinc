#include "Ztextview.h"

Ztextview::Ztextview(int x, int y, int width, int height) :
  Zwidget(x, y, width, height)
{
  // If width or height is less than 3, there will be problems
  if(width < 3)
    this->width = 3;
  if(height < 3)
    this->height = 3;

  this->top_line = 0;
}

void Ztextview::add_word(const std::string &word)
{
  // See if we can fit a word in the current line
  // if not, check the size of the word, can it fit on the next whole line?
  // if not, it must be divided
  if(lines.size() < 1)
    lines.push_back("");

  unsigned int current_line = lines.size() - 1;
  unsigned int word_size = word.size();
  unsigned int pad_width = width - 2;
  unsigned int pad_height = height -2;
  unsigned int current_line_width = lines[current_line].size();

  if(word_size + current_line_width <= pad_width)
  {
    lines[current_line] += word;
    return;
  }
  else
  {
    // Create a new line and keep chopping the word and adding lines
    unsigned int num_cuts = word_size / pad_width;

    // There is a chance that we need an extra line remainder tracks that
    bool remainder = (word_size % pad_width);

    for(int i = 0; i < num_cuts; ++i)
    {
      if(lines[current_line] != "") // First word is too long, use 1st line
      {
	current_line++;
	lines.push_back("");
      }
      lines[current_line] = word.substr(i * pad_width, pad_width); 
    }
    if(remainder) // One additional line is required
    {
      current_line ++;
      lines.push_back("");
      lines[current_line] = word.substr(num_cuts * pad_width); 
    }
  }
}

void Ztextview::set_text(const std::string &str)
{
  std::string word = "";
  lines.clear();

  for(int i = 0; i < str.size(); ++i)
  {
    if(str[i] == '\n' || str[i] == ' ')
    {
      if(word != "")
      {
	add_word(word);
	word = "";
      }
      if(str[i] == '\n') // add a new line
      {
	lines.push_back("");
      }
      else
      {
	add_word(" ");
      }
    }
    else
    {
      word += str[i];
      if(i == str.size() -1  && word != "")
      {
	add_word(word);
      }
    }
  }
}

void Ztextview::set_top_line(unsigned int top)
{
  if(top > lines.size() - 1)
  {
    top_line = lines.size() - 1;    
  }
  else
  {
    top_line = top;
  }
}

unsigned int Ztextview::get_top_line()
{
  return top_line;
}

unsigned int Ztextview::get_num_lines()
{
  return lines.size();
}

void Ztextview::update()
{
  Zwidget::update(); // Call base class' drawing (rectangle)
  unsigned int pad_height = height - 2;
    
  for(unsigned int i = 0, j = top_line; i < pad_height; ++i, ++j)
  {
    if(j < lines.size()) // Ensure you don't read beyond end of lines
      zmove_put(x + 1, y + 1 + i, lines[j]);
    else
      break;
  }
  unsigned int offset = (width - 6) / 2;

  // Draw "more" label if the text can scroll down
  if(lines.size() - top_line> pad_height)
    zmove_put(x + offset, y + height - 1, "[more]");

  // Draw a "back" label if the text can scroll up
  if(top_line > 0)
    zmove_put(x + offset, y, "[back]");
}
