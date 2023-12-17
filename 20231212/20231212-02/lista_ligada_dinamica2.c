#include <stdio.h>
#include <stdlib.h>
#include "lista_ligada_dinamica2.h"

void inicializarLista(ListaLigadaDinamica* lista) {
    lista->head = NULL;
    lista->size = 0;
}

void reiniciarLista(ListaLigadaDinamica* lista) {
    while (lista->head != NULL) {
        Node* temp = lista->head;
        lista->head = lista->head->next;
        free(temp);
    }
    lista->size = 0;
}

void inserirElemento(ListaLigadaDinamica* lista, int elemento) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro: Falha ao alocar memória para um novo nó.\n");
        return;
    }

    newNode->data = elemento;
    newNode->next = lista->head;
    lista->head = newNode;
    lista->size++;
}

void exibirLista(ListaLigadaDinamica* lista) {
    Node* current = lista->head;
    printf("Lista de Elementos: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void percorrerConstruirL1a(ListaLigadaDinamica* lista) {
    if (lista->size <= 1) {
        printf("A lista não possui elementos suficientes para a operação L1a.\n");
        return;
    }

    Node* firstNode = lista->head;
    Node* lastNode = NULL;
    Node* current = lista->head;

    while (current->next != NULL) {
        lastNode = current;
        current = current->next;
    }

    lastNode->next = NULL;
    current->next = firstNode;
    lista->head = current;
}

void percorrerConstruirL1b(ListaLigadaDinamica* lista) {
    if (lista->size <= 1) {
        printf("A lista não possui elementos suficientes para a operação L1b.\n");
        return;
    }

    Node* current = lista->head;
    Node* prev = NULL;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    lista->head = prev;
}

void copiarLista(ListaLigadaDinamica* destino, ListaLigadaDinamica* origem) {
    reiniciarLista(destino);

    Node* current = origem->head;
    while (current != NULL) {
        inserirElemento(destino, current->data);
        current = current->next;
    }
}

void concatenarListas(ListaLigadaDinamica* lista1, ListaLigadaDinamica* lista2) {
    if (lista1->size == 0) {
        lista1->head = lista2->head;
    } else if (lista2->size > 0) {
        Node* current = lista1->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = lista2->head;
    }

    lista1->size += lista2->size;
    lista2->head = NULL;
    lista2->size = 0;
}

void intercalarListas(ListaLigadaDinamica* lista1, ListaLigadaDinamica* lista2) {
    Node* current1 = lista1->head;
    Node* current2 = lista2->head;
    Node* next1, *next2;

    while (current1 != NULL && current2 != NULL) {
        next1 = current1->next;
        next2 = current2->next;

        current1->next = current2;
        current2->next = next1;

        current1 = next1;
        current2 = next2;
    }

    lista2->head = NULL;
    lista2->size = 0;
}
