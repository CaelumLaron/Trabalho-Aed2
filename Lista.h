#ifndef LISTA_H
#define LISTA_H

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
void CriaListaEVetorIguais(int n, ListaEncadeada *lista, int v[]);//Cria lista e vetor de tamanho com mesmos elementos
void DestruirLista(ListaEncadeada *lista);// Só pra ter né, vai que o professor pede pra gente destruir a lista no final e tal

#endif
