#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

typedef struct NoArvore {
    int chave;
    struct NoArvore* esquerda;
    struct NoArvore* direita;
} NoArvore;

typedef struct ArvoreBinaria {
    NoArvore* raiz;
} ArvoreBinaria;

ArvoreBinaria* inicializarArvore();
void inserirElemento(ArvoreBinaria* arvore, int chave);
void imprimirArvore(NoArvore* raiz);
int contarElementos(NoArvore* raiz);
NoArvore* buscarElemento(NoArvore* raiz, int chave);
void preOrdem(NoArvore* raiz);
void emOrdem(NoArvore* raiz);
void posOrdem(NoArvore* raiz);

#endif 
