CC=gcc
CFLAGS=-Wall

test_sieve: sieve_of_eratosthenes.o c_intarray.o
	cc -o a.out sieve_of_eratosthenes.o c_intarray.o -lm
	@./a.out

sieve_of_eratosthenes.o: sieve_of_eratosthenes.c
c_intarray.o: c_intarray.c c_intarray.h

clean:
	rm *.out *.o
