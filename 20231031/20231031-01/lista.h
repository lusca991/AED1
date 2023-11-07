#ifndef LISTA_H
#define LISTA_H

typedef struct{
    int *n;
    int tam;
} Lista;

Lista* criarLista(int tam);
void liberaLista(Lista *lista);
void inserirElemento(Lista *lista, int valor, int posicao);
void imprimir(Lista *lista);
int buscaSequencial(Lista *lista, int valor);
int buscaS_Ordenada(Lista *lista, int valor);
int buscaBinaria(Lista *lista, int valor);
int buscaMaior(Lista *lista);
int buscaMenor(Lista *lista);
int retornarSoma(Lista *lista);
int retornarProduto(Lista *lista);
int buscarNumeroSequencial(Lista *lista, int valor, int *comparacoes);
Lista* criarListaOrdenada(int tam);
int buscarNumeroSequencialOrdenada(Lista *lista, int valor, int *comparacoes);
int buscarNumeroBinariaIterativa(Lista *lista, int valor, int *comparacoes);
void imprimirMaior(Lista *lista);
void imprimirMenor(Lista *lista);
void imprimirSoma(Lista *lista);
void imprimirProduto(Lista *lista);
int buscarNumeroBinariaRecursiva(Lista *lista, int valor, int *comparacoes);
int buscaBinariaRecursivaAux(Lista *lista, int valor, int esq, int dir, int *comparacoes);




#endif