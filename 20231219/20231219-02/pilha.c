#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void inicializarPilha(Pilha* pilha) {
    pilha->topo = -1;
}

int pilhaVazia(const Pilha* pilha) {
    return pilha->topo == -1;
}

int pilhaCheia(const Pilha* pilha) {
    return pilha->topo == MAX_AVIOES - 1;
}

void adicionarAviao(Pilha* pilha, int identificador, const char* nome) {
    if (pilhaCheia(pilha)) {
        printf("O hangar está cheio. Não é possível adicionar mais aviões.\n");
        return;
    }

    Aviao aviao;
    aviao.identificador = identificador;
    strcpy(aviao.nome, nome);

    pilha->topo++;
    pilha->avioes[pilha->topo] = aviao;

    printf("Avião adicionado ao hangar.\n");
}

void listarAvioesHangar(const Pilha* pilha) {
    if (pilhaVazia(pilha)) {
        printf("Não há aviões no hangar.\n");
        return;
    }

    printf("Aviões no hangar:\n");
    for (int i = pilha->topo; i >= 0; i--) {
        printf("Identificador: %d, Nome: %s\n", pilha->avioes[i].identificador, pilha->avioes[i].nome);
    }
}

void listarPrimeiroAviao(const Pilha* pilha) {
    if (pilhaVazia(pilha)) {
        printf("Não há aviões no hangar.\n");
        return;
    }

    Aviao primeiroAviao = pilha->avioes[pilha->topo];
    printf("Primeiro avião no hangar:\n");
    printf("Identificador: %d, Nome: %s\n", primeiroAviao.identificador, primeiroAviao.nome);
}

void removerAviao(Pilha* pilha) {
    if (pilhaVazia(pilha)) {
        printf("Não há aviões no hangar.\n");
        return;
    }

    printf("Avião removido do hangar.\n");

    pilha->topo--;
}

void removerAviaoPosicao(Pilha* pilha, int posicao) {
    if (pilhaVazia(pilha) || posicao <= 0 || posicao > pilha->topo + 1) {
        printf("Posição inválida ou não há aviões suficientes no hangar.\n");
        return;
    }

    printf("Avião removido do hangar pela posição %d.\n", posicao);

    for (int i = posicao - 1; i < pilha->topo; i++) {
        pilha->avioes[i] = pilha->avioes[i + 1];
    }

    pilha->topo--;
}
