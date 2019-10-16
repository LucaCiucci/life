/**
  \file
  Funzione di stampa assegnamento (non modificare)
*/
#include <stdio.h>
#include  "life.h"


void print_life (short** l, unsigned n, unsigned m){
	printf("\033c");  //pulisce lo schermo

	for(int i = 0; i < n; i++){
		for(int j = 0; j<m; j++){
			if(l[i][j] == 0) putchar(' ');
			else putchar('*');
		}
		putchar('\n');
	}

	putchar('\n');
	fflush(stdout);
	return;
}


