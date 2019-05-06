#include "arvoreAVL.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void liberarNo ( avlNo * node )
{
	if ( node == NULL )
		return;

	liberarNo ( node->esq );
	liberarNo ( node->dir );

	free ( node );
}


void liberarMem ( avlArvore * tree )
{
	liberarNo( tree->raiz );
}

avlArvore * iniciaArv ( )
{
	avlArvore * tree = NULL;

	if ( ( tree = malloc ( sizeof ( avlArvore ) ) ) == NULL )
	{
		return NULL;
	}

	tree->raiz = NULL;

	return tree;
}

avlNo * iniciaNo ( int valor )
{
	avlNo * node;

	node = malloc ( sizeof ( avlNo) );
	if ( node == NULL )
	{
		system ( "pause" );
	}

	node->esq = NULL;
	node->dir = NULL;
	node->valor = valor;

	return node;
}


int alturaAvl(avlNo *node){
	int altura_esq = 0;
	int altura_dir = 0;

	if ( node->esq )
		altura_esq = alturaAvl ( node->esq );

	if ( node->dir )
		altura_dir = alturaAvl ( node->dir );

	return ( altura_dir, altura_esq );
}


int fatorBal(avlNo *node){
	int fator = 0;

	if ( node->esq )
		fator += alturaAvl ( node->esq );

	if ( node->dir )
		fator -= alturaAvl ( node->dir );

	return fator;

}



avlNo *rotacaoEsquerda ( avlNo *node ){
	avlNo * temp = node;
	avlNo * esq = temp->esq;

	temp->esq = esq->dir;
	esq->dir = temp;

	return esq;
}

avlNo *rotacaoEsquerdaDupla ( avlNo *node ){
	avlNo *  temp = node;
	avlNo * esq = temp->esq;
	avlNo * dir = esq->dir;

	temp->esq = dir->dir;
	esq->dir = dir->esq;
	dir->esq = esq;
	dir->dir = temp;

	return dir;
}

avlNo *rotacaoDireita ( avlNo *node ){
	avlNo * temp = node;
	avlNo * dir = temp->dir;

	temp->dir = dir->esq;
	dir->esq = temp;

	return dir;
}

avlNo *rotacaoDireitaDupla (avlNo *node){
	avlNo * temp = node;
	avlNo * dir = temp->dir;
	avlNo * esq = dir->esq;

	temp->dir = esq->esq;
	dir->esq = esq->dir;
	esq->dir = dir;
	esq->esq = temp;

	return esq;
	
}



avlNo * balancear_node (avlNo *  node){
	avlNo * node_balanceado = NULL;

	if ( node->esq )
		node->esq = balancear_node ( node->esq );

	if ( node->dir )
		node->dir = balancear_node ( node->dir );

	int fator = fatorBal ( node );

	if ( fator >= 2 )
	{

		if ( fatorBal ( node->esq ) <= -1 )
			node_balanceado = rotacaoEsquerdaDupla ( node );
		else
			node_balanceado =rotacaoEsquerda ( node );

	}
	else if ( fator <= -2 )
	{
		/* pesando pra direita */

		if ( fatorBal ( node->dir ) >= 1 )
			node_balanceado = rotacaoDireitaDupla ( node );
		else
			node_balanceado = rotacaoDireita( node );

	}
	else
	{
		node_balanceado = node;
	}

	return node_balanceado;
}


void balancearArv (avlArvore *  tree){
	avlNo * novaRaiz = NULL;

	novaRaiz = balancear_node ( tree->raiz );

	if ( novaRaiz != tree->raiz )
	{
		tree->raiz = novaRaiz;
	}
}


void inserirA ( avlArvore * tree, int valor ){
	avlNo * novo_node = NULL;
	avlNo * prox = NULL;
	avlNo * ult = NULL;

	if ( tree->raiz == NULL )
	{
		novo_node = iniciaNo ( valor );
		tree->raiz = novo_node;
	}
	else
	{
		prox = tree->raiz;

		while ( prox != NULL )
		{
			ult = prox;

			if ( valor < prox->valor )
			{
				prox = prox->esq;

			}
			else if ( valor > prox->valor )
			{
				prox = prox->dir;
			}
			else if ( valor == prox->valor )
			{
				return;
			}
		}

		novo_node = iniciaNo ( valor );

		if ( valor < ult->valor )
			ult->esq = novo_node;

		if ( valor > ult->valor )
			ult->dir = novo_node;

	}

	balancearArv ( tree );
}


avlNo * encontrarValor (avlArvore * tree, int valor){
	avlNo * atual = tree->raiz;

	while ( atual && atual->valor != valor )
	{
		if ( valor > atual->valor )
			atual = atual->dir;
		else
			atual = atual->esq;
	}

	return atual;
}