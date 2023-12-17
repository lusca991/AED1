#ifndef LISTA_LIGADA_DINAMICA2_H
#define LISTA_LIGADA_DINAMICA2_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} ListaLigadaDinamica;

void inicializarLista(ListaLigadaDinamica* lista);
void reiniciarLista(ListaLigadaDinamica* lista);
void inserirElemento(ListaLigadaDinamica* lista, int elemento);
void exibirLista(ListaLigadaDinamica* lista);
void percorrerConstruirL1a(ListaLigadaDinamica* lista);
void percorrerConstruirL1b(ListaLigadaDinamica* lista);
void copiarLista(ListaLigadaDinamica* destino, ListaLigadaDinamica* origem);
void concatenarListas(ListaLigadaDinamica* lista1, ListaLigadaDinamica* lista2);
void intercalarListas(ListaLigadaDinamica* lista1, ListaLigadaDinamica* lista2);

#endif
