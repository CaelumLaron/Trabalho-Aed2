#include "Lista.h"
#include <stdlib.h>
#include <time.h>

void CriaListaEncadeada(ListaEncadeada *lista){
	lista->prim = NULL;
}

Node* CriaNode(int newDado){
	Node *aux;
	aux = (Node*)malloc(sizeof(Node));
	aux->prox = NULL;
	aux->dado = newDado;
	return aux;
}

void CriaNoListaEncadeada(ListaEncadeada *lista, int newDado){
	Node *i = lista->prim;
	if(i){
		Node *j = lista->last;
		j->prox = CriaNode(newDado);
		lista->last = j->prox;
	}
	else{
		lista->prim = CriaNode(newDado);
		lista->last = lista->prim;
	}
}

int BuscaSequencialListaEncadeada(int chave, ListaEncadeada lista){
	for(Node* i = lista.prim; ; i = i->prox){
		if(!i)
			break;
		if(i->dado == chave)
			return 1;
	}
	return 0;
}

void CriaListaEVetorIguais(int n, ListaEncadeada *lista, int v[]){
	for(int i=0; i<n; i++)
		CriaNoListaEncadeada(lista, v[i]);
}
