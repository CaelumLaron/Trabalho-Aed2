//QUESTAO (1
#include "stdio.h"
#include "Vetor.h"
#include <time.h>

int main(){
 int *V,chave[30];
 int tam = 1000000;
 v = (* int)malloc(1000000*sizeof(int));	
 clock_t tempo1,tempo2;
 double media =0;
 double tempo[30];
 int vseq[30];
 PreencheVetorOrdenado(tam, vetor1);
 for(int i =0;i<30;i++){
 	chave[i] =(rand()%100+1);
 }

for(int i =0;i<30;i++){
	tempo1 = clock();
	BuscaSequencialVetor(chave[i],tam,vetor1);
	tempo2 = clock();
	tempo[i] = ((double)(tempo2-tempo1)/(CLOCKS_PER_SEC/1000));
 }
 printf("BUSCA SEQUENCIAL VETOR \n");
 for(int i =0;i<30;i++){
 	printf("%lf\n",tempo[i]);
 }
 for(int i = 0;i<30;i++){
 	media +=tempo[i];
 }
 printf("\n%lf\n",(media/30));
 
 for(int i =0;i<30;i++){
	tempo1 = clock();
	BuscaBinariaVetor(chave[i],tam,vetor1);
	tempo2 = clock();
	tempo[i] = ((double)(tempo2-tempo1)/(CLOCKS_PER_SEC/1000));
 }
 printf("BUSCA BINÁRIA VETOR \n");
 for(int i =0;i<30;i++){
 	printf("%lf\n",tempo[i]);
 }
 for(int i = 0;i<30;i++){
 	media +=tempo[i];
 }
 printf("\n%lf\n",(media/30));
 free(v);	
}



