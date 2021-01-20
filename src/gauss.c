#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */

int eliminate(Matrix *mat, Matrix *b)
{
	//Eliminacja Gaussa

	int r = mat->r;
	int c = mat->c;

	for(int k = 0; k < c; k++)
	{
		for(int w = k+1; w < r; w++)
		{
			double wsp = mat->data[w][k]/mat->data[k][k];

			for(int j = k; j < c; j++)
				mat->data[w][j] -= mat->data[k][j]*wsp;
			
			b->data[w][0]-=wsp*b->data[k][0];
		}
	}

	return 0;
}

