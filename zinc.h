// ZINC- Zinc Is Not Curses
// A simple and light vt100 library
// Ryan Burnside and Joshua Stylen 2013

#ifndef ZINC_H
#define ZINC_H

#include <iostream>
#include <sstream>

static const char ESC(27);
static std::stringstream text_to_string;


inline std::string zval_to_str(unsigned int x)
{
  // Convert a numeric value to string, good for paramters
  text_to_string.str(std::string());
  text_to_string << x;
  return text_to_string.str();
}

inline void zfont_reset()
{
  std::cout << ESC << "[0m";
}

inline void zfont_bold()
{
  std::cout << ESC << "[1m";
}

inline void zfont_dim()
{
  std::cout << ESC << "[2m";
}

inline void zfont_underline()
{
  std::cout << ESC << "[4m";
}

inline void zfont_blink()
{
  std::cout << ESC << "[5m";
}

inline void zvidya_reverse()
{
  std::cout << ESC << "[7m";
}

inline void zfont_hide_text()
{
  std::cout << ESC << "[8m";
}

//COLORS!!!!!!!!
inline void zfont_black()
{
  std::cout << ESC << "[30m";
}

inline void zfont_red()
{
  std::cout << ESC << "[31m";
}

inline void zfont_green()
{
  std::cout << ESC << "[32m";
}

inline void zfont_yellow()
{
  std::cout << ESC << "[33m";
}

inline void zfont_blue()
{
  std::cout << ESC << "[34m";
}

inline void zfont_magenta()
{
  std::cout << ESC << "[35m";
}

inline void zfont_cyan()
{
  std::cout << ESC << "[36m";
}

inline void zfont_white()
{
  std::cout << ESC << "[37m";
}

//Background colors!!!

inline void zbackfont_black()
{
  std::cout << ESC << "[40m";
}

inline void zbackfont_red()
{
  std::cout << ESC << "[41m";
}

inline void zbackfont_green()
{
  std::cout << ESC << "[42m";
}

inline void zbackfont_yellow()
{
  std::cout << ESC << "[43m";
}

inline void zbackfont_blue()
{
  std::cout << ESC << "[44m";
}

inline void zbackfont_magenta()
{
  std::cout << ESC << "[45m";
}

inline void zbackfont_cyan()
{
  std::cout << ESC << "[46m";
}

inline void zbackfont_white()
{
  std::cout << ESC << "[47m";
}

inline void zwrap(bool wrap)
{
  //AKA autowrap
  std::cout << ESC << "[" << wrap << "h";
}

inline void zhide_cursor()
{
  std::cout << ESC << "[?25l";
}

inline void zshow_cursor()
{
  std::cout << ESC << "[?25h";
}

inline void zclear()
{
  // Write the screen clear character
  std::cout << ESC << "[2J";
}

inline void zmove(unsigned int x, unsigned int y)
{
  // Move the cursor, no writing
  std::string row = zval_to_str(y).c_str();
  std::string column = zval_to_str(x).c_str();
  std::cout << ESC << "[" << row << ';' << column << 'f';
}

inline void zput(unsigned char c)
{
  // Put character at current cursor
  std::cout << c;
}

inline void zput(std::string s)
{
  // Put string at current cursor
  std::cout << s;
}

inline void zmove_put(unsigned int x, unsigned int y, unsigned char c)
{
  // Move the cursor, put a character
  zmove(x, y);
  zput(c);
}

inline void zmove_put(unsigned int x, unsigned int y, std::string s)
{
  // Move the cursor, put a character
  zmove(x, y);
  zput(s);
}

inline void zdraw_horizontal(unsigned int x, unsigned int y, unsigned int length, 
		      unsigned char c, unsigned char b = '+')
{
  //Draw a horizontal line at a given location and length
  for(unsigned int xx = 0; xx < length; ++xx)
  {
    if(xx == 0 || xx == length -1)	  //See if we are at the endpoints
    {
      zmove_put(x + xx, y, b);            //Draw endpoint character b
    }
    else				  //If we are not at the border
    {
      zmove_put(x + xx, y, c);	          //Draw part of the line using c
    }
  }
}

inline void zdraw_vertical(unsigned int x, unsigned int y, unsigned int length, 
		    unsigned char c, unsigned char b = '+')
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

inline void zdraw_frame(unsigned int x, unsigned int y, unsigned int width, 
		 unsigned int height, unsigned char corner = '+',
		 unsigned char side = '|', unsigned char top = '-')
{
  // This is the proper way to draw a hollow frame.
  zdraw_horizontal(x, y, width, top, corner);
  zdraw_horizontal(x, y + height -1, width, top, corner);
  zdraw_vertical(x, y, height, side, corner);
  zdraw_vertical(x + width -1, y, height, side, corner);
}


inline void zdraw_block(unsigned int x, unsigned int y, unsigned int width, 
		 unsigned int height, unsigned char c, 
		 unsigned char corner = ' ',
		 unsigned char side = ' ', unsigned char top = ' ')
{
  // Draws and entire block or character c
  // Border elements can be specified or simply left as filler spaces

  // draw the outside frame
  zdraw_frame(x, y, width, height, corner, side, top);

  // Draw inside frame
  if(width > 0 && height > 0)
  {
    for(unsigned int yy = 0; yy < height - 2; ++yy)
    {
      for(unsigned int xx = 0; xx < width - 2; ++xx)
      {
	zmove_put(x + 1 + xx, y + 1 + yy, c);
      }
    }
  }
}

#endif
