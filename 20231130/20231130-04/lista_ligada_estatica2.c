#include "lista_ligada_estatica2.h"
#include <stdio.h>

void inicializarLista(ListaLigadaEstatica *lista) {
    lista->quantidade = 0;
}

void exibirLista(ListaLigadaEstatica *lista) {
    printf("Lista de elementos: ");
    for (int i = 0; i < lista->quantidade; ++i) {
        printf("%d ", lista->elementos[i]);
    }
    printf("\n");
}

void copiarLista(ListaLigadaEstatica *destino, ListaLigadaEstatica *origem) {
    destino->quantidade = origem->quantidade;
    for (int i = 0; i < origem->quantidade; ++i) {
        destino->elementos[i] = origem->elementos[i];
    }
}

void concatenarListas(ListaLigadaEstatica *lista1, ListaLigadaEstatica *lista2) {
    if (lista1->quantidade + lista2->quantidade > TAMANHO_MAX) {
        printf("Erro: Listas muito grandes para a operação de concatenação.\n");
        return;
    }

    for (int i = 0; i < lista2->quantidade; ++i) {
        lista1->elementos[lista1->quantidade + i] = lista2->elementos[i];
    }

    lista1->quantidade += lista2->quantidade;
}

void intercalarListas(ListaLigadaEstatica *lista1, ListaLigadaEstatica *lista2) {
    if (lista1->quantidade + lista2->quantidade > TAMANHO_MAX) {
        printf("Erro: Listas muito grandes para a operação de intercalação.\n");
        return;
    }

    int i = 0, j = 0;
    ListaLigadaEstatica resultado;
    inicializarLista(&resultado);

    while (i < lista1->quantidade && j < lista2->quantidade) {
        resultado.elementos[resultado.quantidade++] = lista1->elementos[i++];
        resultado.elementos[resultado.quantidade++] = lista2->elementos[j++];
    }

    while (i < lista1->quantidade) {
        resultado.elementos[resultado.quantidade++] = lista1->elementos[i++];
    }

    while (j < lista2->quantidade) {
        resultado.elementos[resultado.quantidade++] = lista2->elementos[j++];
    }

    copiarLista(lista1, &resultado);
}

