#ifndef LISTA_H
#define LISTA_H

typedef struct 
{
 int *n;
 int tam;
} Lista;

Lista* criarLista(int tam);
void imprimir(Lista *lista, int index);
void liberaLista(Lista *lista);
void inserirElemento (Lista *lista, int valor);
void inserirOrdenado (Lista *lista, int valor);
int retornarSoma(Lista *lista, int index);
int retornarProduto(Lista *lista, int index);
int buscaMenor(Lista *lista, int index, int min);
int buscaMaior(Lista *lista, int index, int max);
int buscaBinariaRecursiva(Lista *lista, int valor, int esq, int dir);



#endif