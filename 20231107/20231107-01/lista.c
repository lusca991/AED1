#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

//função de criação da lista do exercício anterior
Lista* criarLista(int tam){
    Lista *lista = (Lista*)malloc(sizeof(Lista));
    lista->tam=tam; 
    lista->n = (int*)malloc(sizeof(int) * tam);
    return lista;
}
//função free do exercício anterior
void liberaLista(Lista *lista ){
    free (lista->n);
    free (lista);
}

//inserção de elemento levemente diferente, sem o valor posição dessa vez
void inserirElemento(Lista *lista, int valor) {
    if (lista->tam < sizeof(lista->n) / sizeof(lista->n[0])) {
        lista->n[lista->tam] = valor;
        lista->tam++;
    } else {
        printf("ERROR, a lista tá cheia doidão o/");
    }
}

//função de inserção ordenada 
void inserirOrdenado(Lista *lista, int valor) {
    int i, j;
    for (i = 0; i < lista->tam; i++) {
        if (lista->n[i] > valor) {
            break;
        }
    }
    for (j = lista->tam; j > i; j--) {
        lista->n[j] = lista->n[j - 1];
    }
    lista->n[i] = valor;
    lista->tam++;
}


//print recursivo e iterativo
void imprimir(Lista *lista, int index) {
    if (index == lista->tam) {
        return;
    }
    printf("%d ", lista->n[index]);
    imprimir(lista, index + 1);
}

//função para buscar um elemento em uma lista usando recursividade sem função auxiliar dessa vez
int buscaBinariaRecursiva(Lista *lista, int valor, int esq, int dir) {
    if (dir >= esq) {
        int meio = esq + (dir - esq) / 2;
        if (lista->n[meio] == valor) {
            return meio;
        }
        if (lista->n[meio] > valor) {
            return buscaBinariaRecursiva(lista, valor, esq, meio - 1);
        }
        return buscaBinariaRecursiva(lista, valor, meio + 1, dir);
    }
    return -1;
}

// Função para buscar o maior elemento em uma lista usando um algoritmo recursivo
int buscaMaior(Lista *lista, int index, int max) {
    if (index == lista->tam) {
        return max;
    }
    if (lista->n[index] > max) {
        max = lista->n[index];
    }
    return buscaMaior(lista, index + 1, max);
}

// Função para buscar o menor elemento em uma lista usando um algoritmo recursivo
int buscaMenor(Lista *lista, int index, int min) {
    if (index == lista->tam) {
        return min;
    }
    if (lista->n[index] < min) {
        min = lista->n[index];
    }
    return buscarMenor(lista, index + 1, min);
}

// Função para retornar a soma de todos os elementos de uma lista usando um algoritmo recursivo
int retornarSoma(Lista *lista, int index) {
    if (index == lista->tam) {
        return 0;
    }
    return lista->n[index] + retornarSoma(lista, index + 1);
}

// Função para retornar o produto de todos os elementos de uma lista usando um algoritmo recursivo
int retornarProduto(Lista *lista, int index) {
    if (index == lista->tam) {
        return 1;
    }
    return lista->n[index] * retornarProduto(lista, index + 1);
}
