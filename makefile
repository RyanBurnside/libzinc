#Check correctness of linking, are both .o files needed?
# Zwidget is the base for Zwindow

test: main.cpp Zwindow.o Zwidget.o
	g++ -o test main.cpp Zwindow.o Zwidget.o

Zwindow.o: Zwindow.cpp Zwindow.h
	g++ -c Zwindow.cpp

Zwidget.o: Zwidget.cpp Zwidget.h
	g++ -c Zwidget.cpp
