#include <stdio.h>
#include <stdlib.h>
#include "lista_ligada_dinamica3.h"

void inicializarLista(ListaDupla* lista) {
    lista->head = NULL;
    lista->tail = NULL;
}

void inserirElemento(ListaDupla* lista, int elemento) {
    Node* novoNode = (Node*)malloc(sizeof(Node));
    if (novoNode == NULL) {
        printf("Erro: Falha ao alocar memória para um novo nó.\n");
        exit(EXIT_FAILURE);
    }

    novoNode->data = elemento;
    novoNode->next = NULL;
    novoNode->prev = NULL;

    if (lista->head == NULL) {
        lista->head = novoNode;
        lista->tail = novoNode;
    } else {
        novoNode->prev = lista->tail;
        lista->tail->next = novoNode;
        lista->tail = novoNode;
    }
}

void exibirLista(ListaDupla* lista) {
    Node* current = lista->head;
    printf("Lista de Elementos: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void criarListaOrdenada(ListaDupla* listaL, ListaDupla* listaK) {
    while (listaL->tail != NULL) {

        Node* removedNode = listaL->tail;

        if (removedNode->prev == NULL) {
            listaL->head = NULL;
            listaL->tail = NULL;
        } else {
            listaL->tail = removedNode->prev;
            listaL->tail->next = NULL;
        }

        removedNode->next = listaK->head;
        removedNode->prev = NULL;

        if (listaK->head != NULL) {
            listaK->head->prev = removedNode;
        }

        listaK->head = removedNode;

        if (listaK->tail == NULL) {
            listaK->tail = removedNode;
        }
    }
}
