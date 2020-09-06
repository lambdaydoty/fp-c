OBJECTS=main.o complex.o
CFLAGS=-Wall
CC=gcc

a.out: $(OBJECTS)
	cc -o a.out $(OBJECTS) -lm

main.o: main.c complex.h bool.h
complex.o: complex.c complex.h

test:
	@./a.out

clean:
	rm *.out *.o
