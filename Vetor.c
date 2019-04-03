#include "Vetor.h"
#include <stdlib.h>

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
		Node *j = list->last;
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

void PreencheVetorOrdenado(int n, int v[]){
	for(int i=0; i<n; i++)
		v[i] =  (i>0)?(v[i-1] + rand()%10+1):(rand()%10+1);
}

void PreencheVetorDesordenado(int n, int v[]){
	for(int i=0; i<n; i++)
		v[i] = rand()%100000 + 1;
}

void CriaListaEVetorIguais(int n, ListaEncadeada *lista, int v[]){
	for(int i=0; i<n; i++){
		int valor = rand()%100000 + 1;
		v[i] = valor;
		CriaNoListaEncadeada(&lista, valor);
	}
}

int BuscaBinariaVetor(int chave, int n, int v[]){
	int ini = 0, fim = n-1, meio;
	while(ini<=fim){
		meio = (ini+fim)/2;
		if(v[meio] < chave)
			ini = meio + 1;
		else if(v[meio] > chave)
			fim = meio - 1;
		else
			return meio;
	}
	return -1;
}

int BuscaSequencialVetor(int chave, int n, int v[]){
	for(int i=0; i<n; i++)
		if(v[i] == chave)
			return i;
	return -1;
}

void BubbleSort(int n, int v[]){
	for(int i=0; i<n-1; i++){
		int troca = i;
		for(int j=i+1; j<n; j++)
			if(v[troca] > v[j])
				troca = j;
		int aux = v[troca];
		v[troca] = v[i];
		v[i] = aux;
	}
}

void InsectionSort(int tamanho, int  v[]) {
	int i, j;
    int pivot; 
    for(j = 1; j < tamanho; j++ ) {
      	i = j -1;
      	pivot = v[j];
      	while((i>=0) && (v[i]>pivot)) {
	  		v[i+1] = v[i];
			i--;
      	}
      v[i+1] = pivot;
    }
 }

void quickSort(int n, int v[]) {
  	qSortInterno(v, 0, n-1);
}

void qSortInterno(int v[], int inicio, int fim) {
  	int pivot;
  	int temp;
  	int i,j;
  	if(fim - inicio > 0) {
    	i = inicio;
    	j = fim;
    	pivot = v[(i+j)/2];
    	do{
      		while(v[i] < pivot) i++; 
      		while(v[j] > pivot) j--; 
      		if(i<= j) { 
				temp = v[i];
				v[i] = v[j];
				v[j] = temp;
				i++; j--;
      		}
    	} while (i<=j);
    	qSortInterno(v,inicio, j);
    	qSortInterno(v, i,fim);
  	}
}
