#include "gauss.h"
#include <stdio.h>
#include <math.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */

int eliminate(Matrix *mat, Matrix *b)
{
	int n = mat->r;

	for(int k = 0; k < n; k++)
	{
		double max = fabs(mat->data[k][k]);
		int wmax = k; //numer wiersza, w ktorym wystepuje dominujacy element

		for(int q = k+1; q < n; q++)
		{
			if(fabs(mat->data[q][k]) > max) 
			{
				wmax = q; //wybieramy wiersz z dominujacym elementem
				max = fabs(mat->data[q][k]);
			}
		}
		if(max == 0) return 1;

		//zamieniamy wiersz
		if(wmax != k)
		{
			double *w_tmp = mat->data[k];
			mat->data[k] = mat->data[wmax];
			mat->data[wmax] = w_tmp;
			
			double *b_tmp = b->data[k];
			b->data[k] = b->data[wmax];
			b->data[wmax] = b_tmp;
		}

		//Eliminacja Gaussa
		double *matk = mat->data[k];
		for(int w = k+1; w < n; w++)
		{
			double *matw = mat->data[w];
			double wsp = matw[k]/matk[k];

			for(int j = k; j < n; j++)
				matw[j] -= matk[j]*wsp;
			b->data[w][0] -= wsp * b->data[k][0];
		}
	}

	if(mat->data[n-1][n-1] == 0) return 1;

	return 0;
}

