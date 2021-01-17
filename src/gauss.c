#include "gauss.h"
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
//zmienne
	double max;
	int r,c;
	r=mat->r;
	c=mat->c;
//szukanie elementu maksyamlnego oraz zamiana wierszy
	for(int i=0;i<c-1;i++)
	{	
		int jmax;
		if(mat->data[i][i]>0)
			max=mat->data[i][i];
		else
			max=-1*(mat->data[i][i]);
		for(int j=i;j<r;j++)
		{
			if(mat->data[j][i]>0)
			{
				if(mat->data[j][i]>max)
				{
					max=mat->data[j][i];
					jmax=j;	
				}
			}
			else
			{
				if((-1*(mat->data[j][i]))>max)
				{
					max=mat->data[j][i];
					jmax=j;
				}
			}
		}
		if(max==0)
		{
			return 1;
		}
		if(jmax!=i)
		{
			double *tmp=mat->data[i];
			mat->data[i]=mat->data[jmax];
			mat->data[jmax]=tmp;
			tmp=b->data[i];
			b->data[i]=b->data[jmax];
			b->data[jmax]=tmp;
		}
//Eliminacja gaussa
		for(int j=i+1;j<r;j++)
		{
			double m=(mat->data[j][i])/(mat->data[i][i]);
			for(int k=i;k<c;k++)
			{
				mat->data[j][k]-=m*(mat->data[i][k]);
			}
			b->data[j][0]-=m*b->data[i][0];
		}
	}
	if(mat->data[r-1][c-1]==0)
	{
		return 1;
	}
		return 0;
}
