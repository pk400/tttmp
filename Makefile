CXX = g++
APP = tttmp
CFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

all:
	$(CXX) $(APP).cpp -o $(APP) $(CFLAGS)
