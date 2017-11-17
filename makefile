all: daycare.c
	gcc -o daycare daycare.c
run: all
	./daycare
