#include "arvore_binaria.h"
#include <stdio.h>
#include <stdlib.h>

NoArvore* criarNo(int chave) {
    NoArvore* novoNo = (NoArvore*)malloc(sizeof(NoArvore));
    if (novoNo != NULL) {
        novoNo->chave = chave;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
    }
    return novoNo;
}

ArvoreBinaria* inicializarArvore() {
    ArvoreBinaria* arvore = (ArvoreBinaria*)malloc(sizeof(ArvoreBinaria));
    if (arvore != NULL) {
        arvore->raiz = NULL;
    }
    return arvore;
}

NoArvore* inserirAuxiliar(NoArvore* raiz, int chave) {
    if (raiz == NULL) {
        return criarNo(chave);
    }
    if (chave < raiz->chave) {
        raiz->esquerda = inserirAuxiliar(raiz->esquerda, chave);
    } else if (chave > raiz->chave) {
        raiz->direita = inserirAuxiliar(raiz->direita, chave);
    }
    return raiz;
}

void inserirElemento(ArvoreBinaria* arvore, int chave) {
    if (arvore != NULL) {
        arvore->raiz = inserirAuxiliar(arvore->raiz, chave);
    }
}

void imprimirArvore(NoArvore* raiz) {
    if (raiz != NULL) {
        imprimirArvore(raiz->esquerda);
        printf("%d ", raiz->chave);
        imprimirArvore(raiz->direita);
    }
}

int contarElementos(NoArvore* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    return 1 + contarElementos(raiz->esquerda) + contarElementos(raiz->direita);
}

NoArvore* buscarElemento(NoArvore* raiz, int chave) {
    if (raiz == NULL || raiz->chave == chave) {
        return raiz;
    }
    if (chave < raiz->chave) {
        return buscarElemento(raiz->esquerda, chave);
    } else {
        return buscarElemento(raiz->direita, chave);
    }
}

void preOrdem(NoArvore* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->chave);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

void emOrdem(NoArvore* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        printf("%d ", raiz->chave);
        emOrdem(raiz->direita);
    }
}

void posOrdem(NoArvore* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%d ", raiz->chave);
    }
}
