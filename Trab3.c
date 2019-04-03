#include "stdio.h"
#include "Vetor.h"
#include <time.h>

int main(){
 	int vetor1[100000];
 	int j =0,tam = 100000;
 	double tempo[3][30];
 	clock_t tempo1,tempo2;
 	double media[3];
 	char codes[3][30] = {"Bubble","Insection","Quick"};
 	for(int i=0,j=0;i<30;i++){
 		PreencheVetorDesordenado(tam,vetor1);
 		tempo1 = clock();
 		BubbleSort(tam,vetor1);
 		tempo2 = clock();
 		tempo[j][i] = ((double)tempo2-tempo1)/CLOCKS_PER_SEC;
  }
 		for(int i=0,j=1;i<30;i++){
    PreencheVetorDesordenado(tam,vetor1);
 		 tempo1 = clock();
 		 InsectionSort(tam,vetor1);
 		 tempo2 = clock();
 		 tempo[j][i] = ((double)tempo2-tempo1)/CLOCKS_PER_SEC;
  }
 	 for(int i =0,j=0;i<30;i++){
 		 tempo1 = clock();
 		 quickSort(tam,vetor1);
 		 tempo2 = clock();
 		 tempo[j][i] = ((double)tempo2-tempo1)/CLOCKS_PER_SEC;	
  }
 	for(int i =0;i<3;i++){
 		printf("Tempos do %s\n",codes[i]);
 		for(int j =0;j<30;j++){
 			printf("%lf\n", tempo[i][j]);
 			media[i]+=tempo[i][j];
 		}
 	}
 	printf("Media Bubble:%lf\n Media Insection:%lf\n MediaQuick:%lf\n",media[0]/30,media[1]/30,media[2]/30);
 }
