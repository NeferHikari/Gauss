#include "backsubst.h"

/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) 
{
	if(mat->r != b->r)
		return 2;

	int r = mat->r;
	int c = mat->c;

	for(int w = r - 1; w >= 0; w--)
	{
		double sum = 0;

		for(int k = w + 1; k < c; k++)
		{
			sum += mat->data[w][k]*x->data[k][0];
		}

		if(mat->data[w][w] == 0) return 1;

		x->data[w][0] = (b->data[w][0] - sum) / mat->data[w][w];
	}

	return 0;
}