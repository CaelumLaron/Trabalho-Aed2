#ifndef ArvABP_H
#define ArvABP_H

typedef struct Arvore{
    int dado;
    struct Arvore *sae;
    struct Arvore *sad;
}Arvore;

Arvore* criarArv(); // cria arvor
void criarArvAle(Arvore **arv, int tam, int v[]);// cria avore com valores aleatórios
Arvore* inserirB(Arvore *arv, int dado);
Arvore* inserir(Arvore *arv, int dado);// inserir na arvore
int buscarnaArv(Arvore *arv, int chave);// busca em arvore
int verifArv(Arvore *arv);// verifica se a arvore está vazia
void mostrarArvemOrdem(Arvore *arv);// Mostra Pré-Ordem
void mostrarArvemPre_Ordem(Arvore *arv);// Mostra Pós-Ordem
void mostrarArvemPos_Ordem(Arvore *arv);// Mostra em-ordem
int alturaArv(Arvore *arv); // Retorna a Altura da Arvore
void preencherarvoreRede(int vet[],int tam, Arvore *arv); // preenche uma arvore com valores aleatórios e repetidos
void destroiArvore(Arvore * arv);//Apaga os elementos da arvore 

#endif