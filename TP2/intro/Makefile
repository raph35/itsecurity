CC=gcc
CFLAG=-g -Wall

TARGET=hello
SRC=main

all: $(TARGET)

$(TARGET) : $(SRC).o
	$(CC) $(CFLAG) -o $(TARGET) $(SRC).o

$(SRC).o : $(SRC).c
	$(CC) -o $(SRC).o -c $(SRC).c

clean:
	rm -f *.o