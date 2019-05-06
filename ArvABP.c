#include <stdio.h>
#include <stdlib.h>
#include "ArvABP.h"

Arvore* criarArv(){
    return NULL;
}
void preencherarvoreRede(int vet[], int tam, Arvore *arv){
	for(int i=0; i<tam; i++)
	   vet[i] = rand()%100000;
    for(int i=0;i<tam;i++)
        inserir(arv,vet[i]);
}

void criarArvAle(Arvore **arv, int tam, int v[]){
    int dado;
    clock_t t;
    srand((unsigned)time(t));
    for(int i=0; i<tam;){
        dado = rand()%(1000000);
        if(!buscarnaArv((*arv), dado)){
            v[i] = dado;
            (*arv) = inserir((*arv),dado);
            i++;
        }
    }
}

Arvore* inserir(Arvore *arv, int dado){ 
    if(!arv){
        arv = (Arvore *)malloc(sizeof(Arvore));
        arv->sae = arv->sad = NULL;
        arv->dado = dado;
        return arv;
    }
    else if(dado > arv->dado)
        arv->sad = inserir(arv->sad,dado);
    else
        arv->sae = inserir(arv->sae,dado);
    return arv;

}

Arvore* inserirB(Arvore *arv, int dado){
    if(!buscarnaArv(arv, dado))
        return inserir(arv, dado);
    return arv;
}

int buscarnaArv(Arvore *arv, int chave){
    if(!arv){
        return 0;
    }
    if(arv->dado == chave){
        return 1;
    }else{
        if(chave > arv->dado){
            return buscarnaArv(arv->sad,chave);
        }else{
            return buscarnaArv(arv->sae,chave);
        }
    }    
}
int verifArv(Arvore *arv){
    return arv == NULL;
}
void mostrarArvemOrdem(Arvore *arv){
    if(!arv)
        return;
    mostrarArvemOrdem(arv->sae);
    printf("%d ",arv->dado);
    mostrarArvemOrdem(arv->sad);
}

void mostrarArvemPre_Ordem(Arvore *arv){
    if(!arv)
        return;
    printf("%d ",arv->dado);
    mostrarArvemPre_Ordem(arv->sae);
    mostrarArvemPre_Ordem(arv->sad);
}

void mostrarArvemPos_Ordem(Arvore *arv){
    if(!arv)
        return;
    mostrarArvemPos_Ordem(arv->sae);
    mostrarArvemPos_Ordem(arv->sad);
    printf("%d ",arv->dado);
}

int alturaArv(Arvore *arv){
    if(!arv){
        return 0;
    }
    int ae = alturaArv(arv->sae);
    int ad = alturaArv(arv->sad);
    if(ae>ad){
        return ae+1;
    }else{
        return ad+1;
    }
}

void destroiArvore(Arvore * arv){
    if(!arv)
        return;
    destroiArvore(arv->sae);
    destroiArvore(arv->sad);
    free(arv);
}
