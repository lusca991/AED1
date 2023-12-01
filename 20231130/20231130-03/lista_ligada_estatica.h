#ifndef LISTA_LIGADA_ESTATICA_H
#define LISTA_LIGADA_ESTATICA_H

#define TAMANHO_MAX 100

typedef struct {
    int elementos[TAMANHO_MAX];
    int quantidade;
} ListaLigadaEstatica;

void inicializarLista(ListaLigadaEstatica *lista);
void exibirLista(ListaLigadaEstatica *lista);
void percorrerListaConstruirL1a(ListaLigadaEstatica *lista);
void percorrerListaConstruirL1b(ListaLigadaEstatica *lista);

#endif
