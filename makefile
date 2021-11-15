all: main.o
	gcc -o parse_args main.c
main.o: 
	gcc -c main.c
run: 
	./parse_args