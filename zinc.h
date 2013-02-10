// ZINC- Zinc Is Not Curses
// A simple and light vt100 library
// Ryan Burnside and Joshua Stylen 2013

#ifndef ZINC_H
#define ZINC_H
#include <iostream>
#include <sstream>

 #ifndef ZINC_INLINE
 #define ZINC_INLINE inline
 #endif

static const char ESC(27);
static std::stringstream text_to_string;

ZINC_INLINE std::string zval_to_str(unsigned int x)
{
  // Convert a numeric value to string, good for paramters
  text_to_string.str(std::string());
  text_to_string << x;
  return text_to_string.str();
}

ZINC_INLINE void zfont_reset()
{
  std::cout << ESC << "[0m";
}

ZINC_INLINE void zfont_bold()
{
  std::cout << ESC << "[1m";
}

ZINC_INLINE void zfont_dim()
{
  std::cout << ESC << "[2m";
}

ZINC_INLINE void zfont_underline()
{
  std::cout << ESC << "[4m";
}

ZINC_INLINE void zfont_blink()
{
  std::cout << ESC << "[5m";
}

ZINC_INLINE void zvidya_reverse()
{
  std::cout << ESC << "[7m";
}

ZINC_INLINE void zfont_hide_text()
{
  std::cout << ESC << "[8m";
}

//COLORS!!!!!!!!
ZINC_INLINE void zfont_black()
{
  std::cout << ESC << "[30m";
}

ZINC_INLINE void zfont_red()
{
  std::cout << ESC << "[31m";
}

ZINC_INLINE void zfont_green()
{
  std::cout << ESC << "[32m";
}

ZINC_INLINE void zfont_yellow()
{
  std::cout << ESC << "[33m";
}

ZINC_INLINE void zfont_blue()
{
  std::cout << ESC << "[34m";
}

ZINC_INLINE void zfont_magenta()
{
  std::cout << ESC << "[35m";
}

ZINC_INLINE void zfont_cyan()
{
  std::cout << ESC << "[36m";
}

ZINC_INLINE void zfont_white()
{
  std::cout << ESC << "[37m";
}

//Background colors!!!

ZINC_INLINE void zbackfont_black()
{
  std::cout << ESC << "[40m";
}

ZINC_INLINE void zbackfont_red()
{
  std::cout << ESC << "[41m";
}

ZINC_INLINE void zbackfont_green()
{
  std::cout << ESC << "[42m";
}

ZINC_INLINE void zbackfont_yellow()
{
  std::cout << ESC << "[43m";
}

ZINC_INLINE void zbackfont_blue()
{
  std::cout << ESC << "[44m";
}

ZINC_INLINE void zbackfont_magenta()
{
  std::cout << ESC << "[45m";
}

ZINC_INLINE void zbackfont_cyan()
{
  std::cout << ESC << "[46m";
}

ZINC_INLINE void zbackfont_white()
{
  std::cout << ESC << "[47m";
}

ZINC_INLINE void zwrap(bool wrap)
{
  //AKA autowrap
  std::cout << ESC << "[" << wrap << "h";
}

ZINC_INLINE void zhide_cursor()
{
  std::cout << ESC << "[?25l";
}

ZINC_INLINE void zshow_cursor()
{
  std::cout << ESC << "[?25h";
}

ZINC_INLINE void zclear()
{
  // Write the screen clear character
  std::cout << ESC << "[2J";
}

ZINC_INLINE void zmove(unsigned int x, unsigned int y)
{
  // Move the cursor, no writing
  std::string row = zval_to_str(y).c_str();
  std::string column = zval_to_str(x).c_str();
  std::cout << ESC << "[" << row << ';' << column << 'f';
}

ZINC_INLINE void zput(unsigned char c)
{
  // Put character at current cursor
  std::cout << c;
}

ZINC_INLINE void zput(std::string s)
{
  // Put string at current cursor
  std::cout << s;
}

ZINC_INLINE void zmove_put(unsigned int x, unsigned int y, unsigned char c)
{
  // Move the cursor, put a character
  zmove(x, y);
  zput(c);
}

ZINC_INLINE void zmove_put(unsigned int x, unsigned int y, std::string s)
{
  // Move the cursor, put a character
  // This should be used instead of the char version for lines of text
  zmove(x, y);
  zput(s);
}

ZINC_INLINE void zdraw_horizontal(unsigned int x, unsigned int y, 
				  unsigned int length, unsigned char c, 
				  unsigned char b = '+')
{
  // make a single horizontal string, then add endpoints
  if(length > 1)
  {
    std::string temp(1, b);
    temp += std::string(length - 2, c);
    temp += b;
    zmove_put(x, y, temp);
  }
}

ZINC_INLINE void zdraw_vertical(unsigned int x, unsigned int y, 
				unsigned int length, unsigned char c, 
				unsigned char b = '+')
{
  //Draw a vertical line at a given location and length
  for(unsigned int yy = 0; yy < length; ++yy)
  {
    if(yy == 0 || yy == length -1)        //See if we are at the endpoints
    {
      zmove_put(x, y + yy, b);            //Draw endpoint character b
    }
    else				  //If we are not at the endpoints
    {
      zmove_put(x, y + yy, c);	          //Draw part of the line using c
    }
  }
}

ZINC_INLINE void zdraw_frame(unsigned int x, unsigned int y, 
			     unsigned int width, unsigned int height, 
			     unsigned char corner = '+', 
			     unsigned char side = '|', unsigned char top = '-')
{
  // This is the proper way to draw a hollow frame.
  zdraw_horizontal(x, y, width, top, corner);
  zdraw_horizontal(x, y + height -1, width, top, corner);
  zdraw_vertical(x, y, height, side, corner);
  zdraw_vertical(x + width -1, y, height, side, corner);
}


ZINC_INLINE void zdraw_block(unsigned int x, unsigned int y, 
			     unsigned int width, unsigned int height, 
			     unsigned char c, unsigned char corner = ' ',
			     unsigned char side = ' ', unsigned char top = ' ')
{
  // Draws and entire block or character c
  // Border elements can be specified or simply left as filler spaces

  // draw the outside frame
  zdraw_frame(x, y, width, height, corner, side, top);
  std::string buffer_fill(width - 2, c);
  // Draw inside frame
  if(width >= 2 && height >= 2)
  {
    for(unsigned int yy = 0; yy < height - 2; ++yy)
    {
      zmove_put(x + 1, y + yy + 1, buffer_fill);
    }
  }
}

#endif
