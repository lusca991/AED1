#ifndef LISTA_LIGADA_DINAMICA3_H
#define LISTA_LIGADA_DINAMICA3_H

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} ListaDupla;

void inicializarLista(ListaDupla* lista);
void inserirElemento(ListaDupla* lista, int elemento);
void exibirLista(ListaDupla* lista);
void criarListaOrdenada(ListaDupla* listaL, ListaDupla* listaK);

#endif