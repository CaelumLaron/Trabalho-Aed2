#ifndef VETOR_H
#define VETOR_H


void PreencheVetorOrdenado(int n, int v[]); // Preenche o vetor aleatoriamente de forma ordenada
int BuscaBinariaVetor(int chave, int n, int v[]);//Realiza busca binária no vetor 
int BuscaSequencialVetor(int chave, int n, int v[]);//Realiza busca sequencial no vetor
void PreencheVetorDesordenado(int n, int v[]); //Preenche o vetor com números aleatórios
void InsectionSort(int tamanho, int  v[]);// Ordena usando insectionSort
void quickSort(int n, int v[]);//Ordena usando QuickSort
void BubbleSort(int n, int v[]);//Ordena usando BubbleSort


#endif
