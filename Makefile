all: prog

run: prog
	./prog

prog: bitwise.o
			gcc bitwise.o -o prog

bitwise.o: bitwise.c
			gcc -c bitwise.c

clean:
			rm *.o
			rm prog

