BIN:=test

SOURCES:=\
  main.cpp \
  Zbutton.cpp \
  Zwidget.cpp \
  Zwindow.cpp \
  zinc.cpp

OBJECTS:=\
  main.o \
  Zbutton.o \
  Zwidget.o \
  Zwindow.o \
  zinc.o

.PHONY: all clean

all: $(BIN)

$(BIN): $(OBJECTS)
	$(CXX) $(CFLAGS) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) -o $@

main.o: main.cpp zinc.h Zwidget.h Zwindow.h Zbutton.h
	$(CXX) $(CFLAGS) $(CXXFLAGS) -c $< -o $@

Zbutton.o: Zbutton.cpp Zbutton.h Zwidget.h zinc.h
	$(CXX) $(CFLAGS) $(CXXFLAGS) -c $< -o $@

Zwidget.o: Zwidget.cpp Zwidget.h zinc.h
	$(CXX) $(CFLAGS) $(CXXFLAGS) -c $< -o $@

Zwindow.o: Zwindow.cpp Zwindow.h Zwidget.h zinc.h
	$(CXX) $(CFLAGS) $(CXXFLAGS) -c $< -o $@

zinc.o: zinc.cpp zinc.h
	$(CXX) $(CFLAGS) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(BIN)
