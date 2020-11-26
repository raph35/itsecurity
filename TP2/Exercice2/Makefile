CC=gcc
CFLAG=-g -Wall
PROGNAME=hello

LDPATH=lib
LDFLAGS=-lprinthello -Wl,-rpath,$(LDPATH)

SRC=main

all : $(PROGNAME)

$(PROGNAME) : main.o memoryAccessProbe.o
	$(CC) $(CFLAG) -o $@ $^ $(LDFLAGS) -L$(LDPATH)

%.o : %.c
	$(CC) $(CFLAG) -o $@ -c $< 

lib : libprinthello.so

libprinthello.so : printhello.o
	$(CC) -shared $^ -o $(LDPATH)/$@

printhello.o : printhello.c
	$(CC) $(CFLAG) -fPIC -o $@ -c $<

clean:
	rm *.o

clean-all:
	rm *.o
	rm $(PROGNAME)