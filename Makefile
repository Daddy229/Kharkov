TARGET = cp 
CC = gcc
LIBS = -lm -lSDL2
CFLAGS = -O3

all:
	$(CC) $(CFLAGS) game.c -c game.o
	$(CC) -o $(TARGET) game.o $(LIBS)
	strip $(TARGET)
clean:
	rm *.o 
	rm $(TARGET)
