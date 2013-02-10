libzinc
=======

This hosts the zinc (Zinc Is Not Curses) library. Zinc is written with vt100 
terminal communication in mind. We like nCurses but wanted to reinvent the 
wheel in a smaller form.

This is a project to built a small "curses" library that can be used on most 
standard POSIX terminals. Terminal speed is expected to be around 9600 BAUD but
lower speeds will still not cause problems.

Programming Style:
-Please adhere to the 79 column rule.(parameter lists are newlined to fit this)
-Underscore notation is the variable style of choice.
-Classes are prefixed with 'Z'.
-Guard Blocks are used in header files for classes.

