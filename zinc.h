// ZINC- Zinc Is Not Curses
// A simple and light vt100 library
// Ryan Burnside and Joshua Stylen 2013

#include <iostream>
#include <sstream>

static const char ESC(27);
static std::stringstream text_to_string;


std::string zval_to_str(unsigned int x)
{
  // Convert a numeric value to string, good for paramters
  text_to_string.str(std::string());
  text_to_string << x;
  return text_to_string.str();
}

void zfont_reset()
{
  std::cout << ESC << "[0m";
}

void zfont_bold()
{
  std::cout << ESC << "[1m";
}

void zfont_dim()
{
  std::cout << ESC << "[2m";
}

void zfont_underline()
{
  std::cout << ESC << "[4m";
}

void zfont_blink()
{
  std::cout << ESC << "[5m";
}

void zvidya_reverse()
{
  std::cout << ESC << "[7m";
}

void zfont_hide_text()
{
  std::cout << ESC << "[8m";
}

//COLORS!!!!!!!!
void zfont_black()
{
  std::cout << ESC << "[30m";
}

void zfont_red()
{
  std::cout << ESC << "[31m";
}

void zfont_green()
{
  std::cout << ESC << "[32m";
}

void zfont_yellow()
{
  std::cout << ESC << "[33m";
}

void zfont_blue()
{
  std::cout << ESC << "[34m";
}

void zfont_magenta()
{
  std::cout << ESC << "[35m";
}

void zfont_cyan()
{
  std::cout << ESC << "[36m";
}

void zfont_white()
{
  std::cout << ESC << "[37m";
}

//Background colors!!!

void zbackfont_black()
{
  std::cout << ESC << "[40m";
}

void zbackfont_red()
{
  std::cout << ESC << "[41m";
}

void zbackfont_green()
{
  std::cout << ESC << "[42m";
}

void zbackfont_yellow()
{
  std::cout << ESC << "[43m";
}

void zbackfont_blue()
{
  std::cout << ESC << "[44m";
}

void zbackfont_magenta()
{
  std::cout << ESC << "[45m";
}

void zbackfont_cyan()
{
  std::cout << ESC << "[46m";
}

void zbackfont_white()
{
  std::cout << ESC << "[47m";
}

void zwrap(bool wrap)
{
  //AKA autowrap
  std::cout << ESC << "[" << wrap << "h";
}

void zhide_cursor()
{
  std::cout << ESC << "[?25l";
}

void zshow_cursor()
{
  std::cout << ESC << "[?25h";
}

void zclear()
{
  // Write the screen clear character
  std::cout << ESC << "[2J";
}

void zmove(unsigned int x, unsigned int y)
{
  // Move the cursor, no writing
  std::string row = zval_to_str(y).c_str();
  std::string column = zval_to_str(x).c_str();
  std::cout << ESC << "[" << row << ';' << column << 'f';
}

void zput(unsigned char c)
{
  // Put character at current cursor
  std::cout << c;
}

void zput(std::string s)
{
  // Put string at current cursor
  std::cout << s;
}

void zmove_put(unsigned int x, unsigned int y, unsigned char c)
{
  // Move the cursor, put a character
  zmove(x, y);
  zput(c);
}

void zmove_put(unsigned int x, unsigned int y, std::string s)
{
  // Move the cursor, put a character
  zmove(x, y);
  zput(s);
}

void zdraw_horizontal(unsigned int x, unsigned int y, unsigned int length, 
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

void zdraw_vertical(unsigned int x, unsigned int y, unsigned int length, 
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

void zdraw_block(unsigned int x, unsigned int y, unsigned int width, 
		 unsigned int height, unsigned char c, bool frame)
{
  // Draws a block of c, adds a border of '+' '-' and '|'
  for(unsigned int yy = 0; yy < height; ++yy)
  {
    for(unsigned int xx = 0; xx < width; ++xx)
    {
      if(frame)                               // if border enabled
      {
	if(yy == 0 || yy == height -1)        // if on top or bottom
	{
	  if(xx == 0 or xx == width -1)       // if corner
	  {
	    zmove_put(x + xx, y + yy, '+');   // draw the 4 '+'
	  }
	  else                                // position not corner
	  {
	    zmove_put(x + xx, y + yy, '-');   // draw '-'
	  }
	}
	else if(xx == 0 || xx == width -1)    // if on sides
	{
	  if(yy > 0 && yy < height -1)        // do not allow overlap corners
	  {
	    zmove_put(x + xx, y + yy, '|');   // place verticle '|'
	  }
	}
	else                                  // just an inner fill character
	{
	  zmove_put(x + xx, y + yy, c);       // not border, draw c
	}
      }
      else
      {
	zmove_put(x + xx, y + yy, c);         
      }
    }
  }
}

void zdraw_frame(unsigned int x, unsigned int y, unsigned int width, 
		 unsigned int height, unsigned char corner = '+',
		 unsigned char side = '|', unsigned char top = '-')
{
  // This is the proper way to draw a hollow frame.
  zdraw_horizontal(x, y, width, top, corner);
  zdraw_horizontal(x, y + height -1, width, top, corner);
  zdraw_vertical(x, y, height, side, corner);
  zdraw_vertical(x + width -1, y, height, side, corner);
}
