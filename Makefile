all:
	gcc -Wall --pedantic src/*.c -o bin/gauss

#podstawowy test
test: all
	bin/gauss dane/A dane/b

#test macierzy 4x4
mat4x4: all
	bin/gauss dane/4x4_A.txt dane/4x4_B.txt

#test z elementem zerowym na diagonali
indx0: all
	bin/gauss dane/indx0_A.txt dane/indx0_B.txt

#test z macierza osobliwa
osob: all
	bin/gauss dane/osob_A.txt dane/osob_B.txt

#test blednych danych wejsciowych
format: all
	bin/gauss dane/format_A.txt dane/format_B.txt
