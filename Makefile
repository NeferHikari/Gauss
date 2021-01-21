all:
	gcc -Wall --pedantic src/*.c -o bin/gauss

test: all
	bin/gauss dane/A dane/b

mat4x4: all
	bin/gauss dane/4x4_A.txt dane/4x4_B.txt

indx0: all
	bin/gauss dane/indx0_A.txt dane/indx0_B.txt

osob: all
	bin/gauss dane/osob_A.txt dane/osob_B.txt

format: all
	bin/gauss dane/format_A.txt dane/format_B.txt
