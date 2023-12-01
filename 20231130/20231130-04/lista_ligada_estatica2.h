#ifndef LISTA_LIGADA_ESTATICA2_H
#define LISTA_LIGADA_ESTATICA2_H

#define TAMANHO_MAX 100

typedef struct {
    int elementos[TAMANHO_MAX];
    int quantidade;
} ListaLigadaEstatica;

void inicializarLista(ListaLigadaEstatica *lista);
void exibirLista(ListaLigadaEstatica *lista);
void copiarLista(ListaLigadaEstatica *destino, ListaLigadaEstatica *origem);
void concatenarListas(ListaLigadaEstatica *lista1, ListaLigadaEstatica *lista2);
void intercalarListas(ListaLigadaEstatica *lista1, ListaLigadaEstatica *lista2);

#endif
