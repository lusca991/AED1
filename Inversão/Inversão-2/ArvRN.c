#include <stdio.h>
#include <stdlib.h>
#include "ArvRN.h"

ArvoreRubroNegra* criarArvore() {
    ArvoreRubroNegra *arvore = (ArvoreRubroNegra*)malloc(sizeof(ArvoreRubroNegra));
    arvore->raiz = NULL;
    return arvore;
}

void destruirArvoreAux(No *raiz) {
    if (raiz != NULL) {
        destruirArvoreAux(raiz->esquerda);
        destruirArvoreAux(raiz->direita);
        free(raiz);
    }
}

void destruirArvore(ArvoreRubroNegra *arvore) {
    destruirArvoreAux(arvore->raiz);
    free(arvore);
}

No* buscar(ArvoreRubroNegra *arvore, int chave) {
    No *atual = arvore->raiz;
    while (atual != NULL && chave != atual->chave) {
        if (chave < atual->chave)
            atual = atual->esquerda;
        else
            atual = atual->direita;
    }
    return atual;
}

void inserir(ArvoreRubroNegra *arvore, int chave) {
    No *z = (No*)malloc(sizeof(No));
    z->chave = chave;
    z->esquerda = z->direita = z->pai = NULL;
    z->cor = VERMELHO;

    No *y = NULL;
    No *x = arvore->raiz;

    while (x != NULL) {
        y = x;
        if (z->chave < x->chave)
            x = x->esquerda;
        else
            x = x->direita;
    }

    z->pai = y;
    if (y == NULL)
        arvore->raiz = z;
    else if (z->chave < y->chave)
        y->esquerda = z;
    else
        y->direita = z;

    verificarInsercao(arvore, z);
}

void verificarInsercao(ArvoreRubroNegra *arvore, No *z) {
    while (z->pai != NULL && z->pai->cor == VERMELHO) {
        if (z->pai == z->pai->pai->esquerda) {
            No *y = z->pai->pai->direita;
            if (y != NULL && y->cor == VERMELHO) {
                z->pai->cor = PRETO;
                y->cor = PRETO;
                z->pai->pai->cor = VERMELHO;
                z = z->pai->pai;
            } else {
                if (z == z->pai->direita) {
                    z = z->pai;
                    rotacaoEsquerda(arvore, z);
                }
                z->pai->cor = PRETO;
                z->pai->pai->cor = VERMELHO;
                rotacaoDireita(arvore, z->pai->pai);
            }
        } else {
            No *y = z->pai->pai->esquerda;
            if (y != NULL && y->cor == VERMELHO) {
                z->pai->cor = PRETO;
                y->cor = PRETO;
                z->pai->pai->cor = VERMELHO;
                z = z->pai->pai;
            } else {
                if (z == z->pai->esquerda) {
                    z = z->pai;
                    rotacaoDireita(arvore, z);
                }
                z->pai->cor = PRETO;
                z->pai->pai->cor = VERMELHO;
                rotacaoEsquerda(arvore, z->pai->pai);
            }
        }
    }
    arvore->raiz->cor = PRETO;
}

void remover(ArvoreRubroNegra *arvore, int chave) {
    No *z = buscar(arvore, chave);
    if (z != NULL) {
        verificarRemocao(arvore, z);
        free(z);
    }
}

void verificarRemocao(ArvoreRubroNegra *arvore, No *x) {
    No *y = x;
    No *xOriginal = x;
    int corOriginal = y->cor;

    No *filho;
    if (x->esquerda == NULL) {
        filho = x->direita;
        transplantar(arvore, x, x->direita);
    } else if (x->direita == NULL) {
        filho = x->esquerda;
        transplantar(arvore, x, x->esquerda);
    } else {
        y = minimo(x->direita);
        corOriginal = y->cor;
        filho = y->direita;
        if (y->pai == x)
            filho->pai = y;
        else {
            transplantar(arvore, y, y->direita);
            y->direita = x->direita;
            y->direita->pai = y;
        }
        transplantar(arvore, x, y);
        y->esquerda = x->esquerda;
        y->esquerda->pai = y;
        y->cor = x->cor;
    }
    free(xOriginal);

    if (corOriginal == PRETO)
        corrigirRemocao(arvore, filho);
}

void corrigirRemocao(ArvoreRubroNegra *arvore, No *x) {
    while (x != arvore->raiz && cor(x) == PRETO) {
        if (x == x->pai->esquerda) {
            No *irmaoX = x->pai->direita;
            if (cor(irmaoX) == VERMELHO) {
                irmaoX->cor = PRETO;
                x->pai->cor = VERMELHO;
                rotacaoEsquerda(arvore, x->pai);
                irmaoX = x->pai->direita;
            }
            if (cor(irmaoX->esquerda) == PRETO && cor(irmaoX->direita) == PRETO) {
                irmaoX->cor = VERMELHO;
                x = x->pai;
            } else {
                if (cor(irmaoX->direita) == PRETO) {
                    irmaoX->esquerda->cor = PRETO;
                    irmaoX->cor = VERMELHO;
                    rotacaoDireita(arvore, irmaoX);
                    irmaoX = x->pai->direita;
                }
                irmaoX->cor = cor(x->pai);
                x->pai->cor = PRETO;
                irmaoX->direita->cor = PRETO;
                rotacaoEsquerda(arvore, x->pai);
                x = arvore->raiz;
            }
        } else {
            No *irmaoX = x->pai->esquerda;
            if (cor(irmaoX) == VERMELHO) {
                irmaoX->cor = PRETO;
                x->pai->cor = VERMELHO;
                rotacaoDireita(arvore, x->pai);
                irmaoX = x->pai->esquerda;
            }
            if (cor(irmaoX->direita) == PRETO && cor(irmaoX->esquerda) == PRETO) {
                irmaoX->cor = VERMELHO;
                x = x->pai;
            } else {
                if (cor(irmaoX->esquerda) == PRETO) {
                    irmaoX->direita->cor = PRETO;
                    irmaoX->cor = VERMELHO;
                    rotacaoEsquerda(arvore, irmaoX);
                    irmaoX = x->pai->esquerda;
                }
                irmaoX->cor = cor(x->pai);
                x->pai->cor = PRETO;
                irmaoX->esquerda->cor = PRETO;
                rotacaoDireita(arvore, x->pai);
                x = arvore->raiz;
            }
        }
    }
    x->cor = PRETO;
}

void rotacaoEsquerda(ArvoreRubroNegra *arvore, No *x) {
    No *y = x->direita;
    x->direita = y->esquerda;
    if (y->esquerda != NULL)
        y->esquerda->pai = x;
    y->pai = x->pai;
    if (x->pai == NULL)
        arvore->raiz = y;
    else if (x == x->pai->esquerda)
        x->pai->esquerda = y;
    else
        x->pai->direita = y;
    y->esquerda = x;
    x->pai = y;
}

void rotacaoDireita(ArvoreRubroNegra *arvore, No *x) {
    No *y = x->esquerda;
    x->esquerda = y->direita;
    if (y->direita != NULL)
        y->direita->pai = x;
    y->pai = x->pai;
    if (x->pai == NULL)
        arvore->raiz = y;
    else if (x == x->pai->direita)
        x->pai->direita = y;
    else
        x->pai->esquerda = y;
    y->direita = x;
    x->pai = y;
}

int cor(No *x) {
    return x == NULL ? PRETO : x->cor;
}

No* irmao(No *x) {
    if (x->pai == NULL)
        return NULL;
    if (x == x->pai->esquerda)
        return x->pai->direita;
    else
        return x->pai->esquerda;
}

No* tio(No *x) {
    return irmao(x->pai);
}

No* minimo(No *x) {
    while (x->esquerda != NULL)
        x = x->esquerda;
    return x;
}

void transplantar(ArvoreRubroNegra *arvore, No *u, No *v) {
    if (u->pai == NULL)
        arvore->raiz = v;
    else if (u == u->pai->esquerda)
        u->pai->esquerda = v;
    else
        u->pai->direita = v;
    if (v != NULL)
        v->pai = u->pai;
}

void balancear(ArvoreRubroNegra *arvore, No *x) {
    while (x != arvore->raiz && x->pai->cor == VERMELHO) {
        if (x->pai == x->pai->pai->esquerda) {
            No *y = x->pai->pai->direita;
            if (y != NULL && y->cor == VERMELHO) {
                x->pai->cor = PRETO;
                y->cor = PRETO;
                x->pai->pai->cor = VERMELHO;
                x = x->pai->pai;
            } else {
                if (x == x->pai->direita) {
                    x = x->pai;
                    rotacaoEsquerda(arvore, x);
                }
                x->pai->cor = PRETO;
                x->pai->pai->cor = VERMELHO;
                rotacaoDireita(arvore, x->pai->pai);
            }
        } else {
            No *y = x->pai->pai->esquerda;
            if (y != NULL && y->cor == VERMELHO) {
                x->pai->cor = PRETO;
                y->cor = PRETO;
                x->pai->pai->cor = VERMELHO;
                x = x->pai->pai;
            } else {
                if (x == x->pai->esquerda) {
                    x = x->pai;
                    rotacaoDireita(arvore, x);
                }
                x->pai->cor = PRETO;
                x->pai->pai->cor = VERMELHO;
                rotacaoEsquerda(arvore, x->pai->pai);
            }
        }
    }
    arvore->raiz->cor = PRETO;
}

void imprimirEmOrdem(No *raiz) {
    if (raiz != NULL) {
        imprimirEmOrdem(raiz->esquerda);
        printf("%d ", raiz->chave);
        imprimirEmOrdem(raiz->direita);
    }
}

// Função para imprimir a árvore
void imprimirArvore(ArvoreRubroNegra *arvore) {
    printf("Árvore rubro-negra: ");
    imprimirEmOrdem(arvore->raiz);
    printf("\n");
}