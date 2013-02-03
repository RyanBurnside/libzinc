# Zwidget is the base for Zwindow and Zbutton

test: main.cpp Zwidget.o Zwindow.o Zbutton.o
	g++ -o test main.cpp Zwidget.o Zwindow.o Zbutton.o

Zbutton.o: Zbutton.cpp Zbutton.h zinc.h
	g++ -c Zbutton.cpp

Zwindow.o: Zwindow.cpp Zwindow.h zinc.h
	g++ -c Zwindow.cpp

Zwidget.o: Zwidget.cpp Zwidget.h zinc.h
	g++ -c Zwidget.cpp
