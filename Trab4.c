#include "Vetor.h" 
#include "Lista.h"
#define tamanho 1000000
int main(){
	int *v = (int*)malloc(tamanho*sizeof(int));
	scanf("%*c ");
	PreencheVetorOrdenado(tamanho, v);
	scanf("%*c");
	return 0;
}
