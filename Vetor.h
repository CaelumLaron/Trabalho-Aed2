#ifndef VETOR_H
#define VETOR_H

typedef struct Node{
	int dado;
	struct Node *prox;
}Node;

typedef struct ListaEncadeada{
	Node *prim, *last;
}ListaEncadeada;

void CriaListaEncadeada(ListaEncadeada *lista); // Cria Lista encadeada
Node* CriaNode(int newDado); // cria um novo no
void CriaNoListaEncadeada(ListaEncadeada *lista, int newDado); //Cria um novo no na Lista
int BuscaSequencialListaEncadeada(int chave, ListaEncadeada lista); //Faz uma busca sequencial na lista
void PreencheVetorOrdenado(int n, int v[]); // Preenche o vetor aleatoriamente de forma ordenada
void CriaListaEVetorIguais(int n, ListaEncadeada *lista, int v[]);//Cria lista e vetor de tamanho com mesmos elementos
int BuscaBinariaVetor(int chave, int n, int v[]);//Realiza busca binária no vetor 
int BuscaSequencialVetor(int chave, int n, int v[]);//Realiza busca sequencial no vetor
void PreencheVetorDesordenado(int n, int v[]); //Preenche o vetor com números aleatórios
void InsectionSort(int tamanho, int  v[]);// Ordena usando insectionSort
void quickSort(int n, int v[]);//Ordena usando QuickSort
void BubbleSort(int n, int v[]);//Ordena usando BubbleSort


#endif
