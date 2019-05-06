#include "ArvABP.h"
#include <stdio.h>

//gcc ArvABP.c Quest2.c -w -o quest2

void RandomPartialSort(int tam, int v[]){
	int *x = (int *)malloc(sizeof(int)*tam);
	for(int i=0; i<tam; i++)
		x[i] = 0;
	int nTam = tam*9/10, nRepe = tam/10;
	int size = 0, repe = 0;
	while(size<tam){
		int index = rand()%nTam;
		if(x[index] == 0){
			v[size++] = index + 1;
			x[index] = 1;
		}
		else if(repe < nRepe){
			repe++;
			v[size++] = index + 1;
		}
	}
}

int main(){
	int values[60];
	Arvore *myArv;
	myArv = criarArv();

	RandomPartialSort(50, values);

	printf("\nPacotes recebidos: \n");
	for(int i=0; i<50; i++){
		myArv = inserirB(myArv, values[i]);
		printf("%d%c", values[i], (i==49)?'\n':' ');
	}	
	
	printf("\n\nPacotes postos em ordem: \n");
	mostrarArvemOrdem(myArv);

	printf("\n\n");
	destroiArvore(myArv);
	return 0;
}