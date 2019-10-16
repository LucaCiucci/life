#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "life.h"
int main(int argc, char** argv)
{
	//srand(time(NULL));
	int nStep = 1;
	const char* fileName = NULL;
	int n = 10, m = 10, h = 25;

	if (argc <= 1)
	{
		// non sono stati passati parametri
		printf("niente mparametri\n");
	}
	else
	{
		// sono stati passati parametri

		bool fileNameFound = false;
		bool nStepFound = false;

		printf("%d parametri\n", argc - 1);

		// troviamo i parametri
		for (int i = 1; i < argc; i++)
		{
			// cerca "-s"
			if (!nStepFound && strcmp(argv[i], "-s") == 0)
			{
				if (i >= argc - 1)// se -s è l'ultimo dei parametri
				{
					printf("dopo -s ci vuole il numero di passi");
					return -1;// esci
				}
				else
				{
					nStep = atoi(argv[i + 1]);// converte il parametro successivo in numero
					if (nStep <= 0)// se c'e stato un errore o n < 0
					{
						printf("dopo -s ci vuole il numero di passi > 0");
						return -1;
					}
					// altrimenti ho trovato il numero
					nStepFound = true;
					i++;// dopo parto dal parametro dopo
					continue;
				}
			}
			if (!fileNameFound && argv[i][0] != '-')
			{
				fileNameFound = true;
				fileName = argv[i];
				printf("nome file = %s\n", fileName);
				continue;
			}
		}
	}


	// solo per test, elimina
	short** mat = crea_life(n, m, h);
	print_life(mat, n, n);

	printf("numero di passi: %d", nStep);
	printf("\n\n\n\n");
	return 0;
}