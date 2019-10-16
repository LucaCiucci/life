#include "life.h"
#include <stdlib.h>

short** crea_life(unsigned n, unsigned m, unsigned h)
{
	if (n <= 2 || m <= 2)
		return NULL;

	const int N = n * m;// numero di celle

	short* matData = (short*)malloc(sizeof(short) * N);
	short** mat = (short**)malloc(sizeof(short*) * n);

	if (matData == NULL || mat == NULL)
		return NULL;

	// numero di celle libere
	int freeCells = N;
	if (freeCells > h)
	{
		// metti tutto a 0;
		for (int i = 0; i < N; i++)
			matData[i] = 0;


		// per ogni punto da inserire
		for (int i = 0; i < h; i++)
		{
			if (freeCells <= 0)
				// l'area è piena
				break;

			// genera una posizione casuale
			int k = rand() % (freeCells);

			// cammina fino a trovare quella psizione
			int j = 0;
			for (int i = 0; i < k; i++, j++)
			{
				while (matData[j % N] != 0)
					j++;
			}
			// riempi la cella selezionata
			matData[j % N] = (short)1;
		}
	}
	else// riempi tutta l'area
	{
		// metti tutto a 1;
		for (int i = 0; i < N; i++)
			matData[i] = 1;
	}

	for (int i = 0; i < n; i++)
	{
		mat[i] = &(matData[i * m]);// oppure  = matData + m * sizeof(short)
	}

	return mat;
}