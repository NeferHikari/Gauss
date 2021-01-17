#include "backsubst.h"

/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
	/*int i;
	for (i =0; i < x->r; i++) 
	{
		x->data[i][0] = b->data[i][0];
	}*/
	if(mat->r != b->r || mat->r != mat->c)
	{
		return 2;
	}
	int r=mat->r;
	int c=mat->c;
	for(int i=r-1;i>=0;i--)
	{	
		double sum=0.0;
		for(int j=i;j<c;j++)
		{
			sum=sum+mat->data[i][j]*x->data[j][0];
		}
	if(mat->data[i][i]==0)
	{
		return 1;
	}
	x->data[i][0]=(b->data[i][0]-sum)/mat->data[i][i];
	}
	return 0;
}


