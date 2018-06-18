CC=g++
CFLAGS=-std=c++0x -g
SRCS=balance.cpp
EXEC=balance

all: $(SOURCES)
	$(CC) $(CFLAGS) $(SRCS) -o $(EXEC)

clean: 
	rm balance *~ 
