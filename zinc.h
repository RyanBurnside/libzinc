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

void zrect_put(unsigned int x, unsigned int y, unsigned int width, 
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

void zdraw_horizontal(unsigned int x, unsigned int y, unsigned int length, unsigned char c, unsigned char b, bool frame)
{
  //Draw a horizontal line at a given location and length
  for(unsigned int xx = 0; xx < length; xx++)
    {
      if(frame)					//If a frame is requested...
        {
          if(xx == 0 || xx == length -1)	//See if we are at a border
          {
            zmove_put(x + xx, y, b);		//Draw Part of the border using character b
          }
          else					//If we are not at the border
          {
	    zmove_put(x + xx, y, c);		//Draw part of the line using c
          }
        }
      else					//If a frame is NOT requested...
        {
          zmove_put(x + xx, y, c);		//Draw c for part of the line
        }
    }
}

void zdraw_vertical(unsigned int x, unsigned int y, unsigned int length, unsigned char c, unsigned char b, bool frame)
{
  //Draw a vertical line at a given location and length
  for(unsigned int yy = 0; yy < length; yy++)
    {
      if(frame)					//If a frame is requested...
        {
          if(yy == 0 || yy == length -1)	//See if we are at a border
          {
            zmove_put(x, y - yy, b);		//Draw Part of the border using character b
          }
          else					//If we are not at the border
          {
	    zmove_put(x, y - yy, c);		//Draw part of the line using c
          }
        }
      else					//If a frame is NOT requested...
        {
          zmove_put(x, y - yy, c);		//Draw c for part of the line
        }
    }
}


















