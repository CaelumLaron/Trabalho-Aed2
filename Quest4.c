#include <stdio.h>
#include <time.h>
#include "ArvABP.h"
#include "arvoreAVL.h"
#include "Vetor.h"

//gcc ArvABP.c arvoreAVL.c Vetor.c Quest4.c -w -o quest4

#define NovoVetor 0
#define TamArv 1000000

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

int main(){
	int v[TamArv], chaves[30];
	clock_t Ticks[2];
	Arvore* arvAbp[10];
	avlArvore *arvAvl[10];
	float mediaAvl=0.0, mediaAbp=0.0;
	for(int i=0; i<30; i++)
		chaves[i] = (i==0)? 0 : (chaves[i-1] + TamArv/30);
	if(!NovoVetor)
		RandomPartialSort(TamArv, v);
	//Comparar criarArvs
	for(int i=0; i<10; i++){
		//printf("ff\n");
		if(NovoVetor)
			RandomPartialSort(TamArv, v);
		//Criar abp
		Ticks[0] = clock();
		arvAbp[i] = criarArv();
		for(int j=0; j<TamArv; j++)
			arvAbp[i] = inserir(arvAbp[i], v[j]);
		Ticks[1] = clock();
		float timeAbp = (Ticks[1] - Ticks[0])*1000.0/CLOCKS_PER_SEC;
		mediaAbp += timeAbp;
		printf("Tempo abp = %f ms\n", timeAbp);
		//Criar avl
		Ticks[0] = clock();
		arvAvl[i] = iniciaArv();
		for(int j=0; j<TamArv; j++)
			inserirA(arvAvl[i], v[j]);
		Ticks[1] = clock();
		float timeAvl = (Ticks[1] - Ticks[0])*1000.0/CLOCKS_PER_SEC;
		mediaAvl += timeAvl;
		
		printf("Altura Abp = %d\nAltura Avl = %d\n", alturaArv(arvAbp[i]), alturaAvl(arvAvl[i]->raiz));
		printf("Tempo Abp = %f ms\nTempoAVl = %f ms\n\n", timeAbp, timeAvl);
	}
	printf("Media Abp = %f ms\nMedia AVl = %f ms\n\n", mediaAbp/10, mediaAvl/10);
	mediaAbp = mediaAvl = 0.0;
	for(int i=0; i<30; i++){
		Ticks[0] = clock();
			buscarnaArv(arvAbp[0], v[chaves[i]]);
		Ticks[1] = clock();
		float timeAbp = (Ticks[1] - Ticks[0])*1000.0/CLOCKS_PER_SEC;
		mediaAbp += timeAbp;

		Ticks[0] = clock();
			encontrarValor(arvAvl[0], v[chaves[i]]);
		Ticks[1] = clock();
		float timeAvl = (Ticks[1] - Ticks[0])*1000.0/CLOCKS_PER_SEC;
		mediaAvl += timeAvl;
		
		printf("Tempo Abp = %f ms\nTempoAVl = %f ms\n\n", timeAbp, timeAbp);
	}
	printf("Media Abp = %f ms\nMedia AVl = %f ms\n\n", mediaAbp/10, mediaAvl/10);
	return 0;
}