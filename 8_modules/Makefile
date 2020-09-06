CC=gcc
CFLAGS=-Wall
OBJECTS=main.o complex.o

a.out: $(OBJECTS)
	cc -o a.out $(OBJECTS) -lm

main.o: main.c complex.h ../common/bool.h
complex.o: complex.c complex.h

test:
	@./a.out

clean:
	rm *.out *.o
