#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#define MAX_AVIOES 100

void inicializarFila(Fila* fila) {
    fila->inicio = 0;
    fila->fim = -1;
    fila->tamanho = 0;
}

int filaVazia(const Fila* fila) {
    return fila->tamanho == 0;
}

int filaCheia(const Fila* fila) {
    return fila->tamanho == MAX_AVIOES;
}

void adicionarAviao(Fila* fila, int identificador, const char* nome) {
    if (filaCheia(fila)) {
        printf("A fila de decolagem está cheia. Não é possível adicionar mais aviões.\n");
        return;
    }

    Aviao aviao;
    aviao.identificador = identificador;
    strcpy(aviao.nome, nome);

    fila->fim = (fila->fim + 1) % MAX_AVIOES;
    fila->avioes[fila->fim] = aviao;
    fila->tamanho++;

    printf("Avião adicionado à fila de decolagem.\n");
}

void listarAvioesEspera(const Fila* fila) {
    if (filaVazia(fila)) {
        printf("Não há aviões aguardando na fila de decolagem.\n");
        return;
    }

    printf("Aviões aguardando na fila de decolagem:\n");
    int i;
    for (i = fila->inicio; i != fila->fim; i = (i + 1) % MAX_AVIOES) {
        printf("Identificador: %d, Nome: %s\n", fila->avioes[i].identificador, fila->avioes[i].nome);
    }
    printf("Identificador: %d, Nome: %s\n", fila->avioes[i].identificador, fila->avioes[i].nome);
}

void listarPrimeiroAviao(const Fila* fila) {
    if (filaVazia(fila)) {
        printf("Não há aviões aguardando na fila de decolagem.\n");
        return;
    }

    Aviao primeiroAviao = fila->avioes[fila->inicio];
    printf("Primeiro avião na fila de decolagem:\n");
    printf("Identificador: %d, Nome: %s\n", primeiroAviao.identificador, primeiroAviao.nome);
}

void autorizarDecolagem(Fila* fila) {
    if (filaVazia(fila)) {
        printf("Não há aviões aguardando na fila de decolagem.\n");
        return;
    }

    Aviao primeiroAviao = fila->avioes[fila->inicio];
    printf("Avião autorizado para decolagem:\n");
    printf("Identificador: %d, Nome: %s\n", primeiroAviao.identificador, primeiroAviao.nome);

    fila->inicio = (fila->inicio + 1) % MAX_AVIOES;
    fila->tamanho--;
}

