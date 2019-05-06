#include "ArvABP.h"
#include <stdio.h>

//gcc ArvABP.c Quest1.c -w -o quest1

int main(){
	int values[50];
	Arvore *myArv;
	myArv = criarArv();
	criarArvAle(&myArv, 50, values);

	printf("\nValores inseridos na Arvore: \n");
	for(int i=0; i<50; i++)
		printf("%d%c", values[i], (i==49)?'\n':' ');

	printf("\n\nEncaminhamento Pre-fixado: \n");
	mostrarArvemPre_Ordem(myArv);
	
	printf("\n\nEncaminhamento infixado: \n");
	mostrarArvemOrdem(myArv);
	
	printf("\n\nEncaminhamento Pos-fixado: \n");
	mostrarArvemPos_Ordem(myArv);

	printf("\n\n");
	destroiArvore(myArv);
	return 0;
}