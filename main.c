#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	int nStep = 1;

	if (argc <= 1)
	{
		printf("niente mparametri\n");
	}
	else
	{
		printf("%d parametri\n", argc - 1);

		// troviamo i parametri
		for (int i = 1; i < argc; i++)
		{
			// cerca "-s"
			if (strcmp(argv[i], "-s") == 0)
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
					break;
				}
			}
		}
	}


	printf("numero di passi: %d", nStep);
	printf("\n\n\n\n");
	return 0;
}