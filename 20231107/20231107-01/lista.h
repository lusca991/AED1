#ifndef LISTA_H
#define LISTA_H

typedef struct 
{
 int *n;
 int tam; //quantidade
} Lista;

Lista* criarLista(int tam);
void imprimir(Lista *lista);
void imprimirRecursivo(Lista *lista, int index);
void liberaLista(Lista *lista);
void inserirElemento (Lista *lista, int valor);
void inserirOrdenado (Lista *lista, int valor);
int retornarSomaRecursiva(Lista *lista, int index, int soma);
int retornarProdutoRecursiva(Lista *lista, int index);
int buscaMenorrRecursivo(Lista *lista, int index, int menor);
int buscaMaiorRecursivo(Lista *lista, int index, int maior);
int buscaBinariaRecursiva(Lista *lista, int valor, int esq, int dir);



#endif