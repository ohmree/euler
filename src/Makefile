CC=gcc
RFLAGS=-O2 -Wall -std=gnu11 #-o bin/release/
DFLAGS=-O0 -Wall -std=gnu11 -g #-o bin/debug/
DFLAGS+=$(CCOPTS)
RFLAGS+=$(CCOPTS)
SRC=$(wildcard *.c)
OBJ=$(wildcard *.o)
LIBS=-lm

release: $(SRC)
	$(CC) -o $@ $^ $(RFLAGS) $(LIBS)
