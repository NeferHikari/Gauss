all:
	gcc -ggdb -Wall --pedantic src/*.c -o bin/gauss

test: all
	bin/gauss dane/A dane/b
