CC=g++
FLAGS=-std=c++11
SOURCE=*.cpp
TARGET=-o main
LIBS=
all:
	$(CC) $(FLAGS) $(SOURCE) $(TARGET) $(LIBS)
