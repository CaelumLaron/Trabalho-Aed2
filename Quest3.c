#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Vetor.h"
#include "ArvABP.h"

//gcc ArvABP.c Vetor.c Quest3.c -w -o quest3

#define DEBUG 0
#define ArvTam 1000000
// DONE
void RandomPartialSort(int tam, int v[]){
	int *x = (int *)malloc(sizeof(int)*tam);
	for(int i=0; i<tam; i++)
		x[i] = 0;
	int size = 0;
	while(size<tam){
		int index = rand()%tam + 1;
		if(x[index] == 0){
			v[size++] = index + 1;
			x[index] = 1;
		}
	}
	free(x);
}

int pow2(int pot){
	int ans = 1;
	while(pot--)
		ans *= 2;
	return ans;
}

int main(){
	
	int v[ArvTam], chaves[30];
	clock_t Ticks[2];
	Arvore *myArv = criarArv();
	float mediaVetor, mediaArvore;
	for(int i=0; i<30; i++)
		chaves[i] = (i==0)? 0 : (chaves[i-1] + ArvTam/30);
	printf("Antes de usar o vetor de %lf MiB: \n", ((double)sizeof(int)*ArvTam)/pow2(20));
	getchar();
	RandomPartialSort(ArvTam, v);
	printf("Antes de iniciar a arvore de %lf MiB: \n",((double)sizeof(Arvore)*ArvTam)/pow2(20));
	getchar();
	for(int i=0; i<ArvTam; i++)
			myArv = inserir(myArv, v[i]);
	quickSort(ArvTam, v);
	mediaArvore = mediaVetor = 0.0;
	for(int i=0; i<30; i++){
		float buscaBin, buscaAbp;
		Ticks[0] = clock();
			BuscaBinariaVetor(v[chaves[i]], ArvTam, v);
		Ticks[1] = clock();
		buscaBin = (Ticks[1] - Ticks[0])*1000.0/CLOCKS_PER_SEC;
		Ticks[0] = clock();
			buscarnaArv(myArv, v[chaves[i]]);
		Ticks[1] = clock();
		buscaAbp = (Ticks[1] - Ticks[0])*1000.0/CLOCKS_PER_SEC; 
		mediaVetor += buscaBin;
		mediaArvore += buscaAbp;
		printf("Teste %d:\nVetor: %f ms\nArvore: %f ms\n\n",i+1, buscaBin, buscaAbp);
		if(DEBUG)
			getchar();
	}
	printf("Antes de destruir a arvore: \n");
	getchar();
	destroiArvore(myArv);
	printf("Depois de destruir a arvore: \n");
	getchar();
	printf("Media Arvore = %f ms\nMedia busca Binaria = %f ms\n", mediaArvore/30, mediaVetor/30);
	return 0;
}