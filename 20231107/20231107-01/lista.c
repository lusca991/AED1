#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

//função para criar uma nova LISTA 
Lista* criarLista(int tam) {
    Lista *novaLista = (Lista*)malloc(sizeof(Lista));
    if (novaLista == NULL) {
        return NULL; 
    }
    novaLista->n = (int*)malloc(tam * sizeof(int));
    if (novaLista->n == NULL) {
        free(novaLista);
        return NULL; 
    }
    novaLista->tam = tam;
    return novaLista;
}

//função free
void liberaLista(Lista *lista) {
    if (lista != NULL) {
        free(lista->n);
        free(lista);
    }
}

//função de inserção
void inserirElemento(Lista *lista, int valor) {
    if (lista != NULL) {
        // Insira o valor no final da lista (você pode adicionar lógica para inserção ordenada)
        lista->n[lista->tam++] = valor;
    }
}

//função para inserção elemento de forma ordenada 
void inserirOrdenado(Lista *lista, int valor) {
    if (lista != NULL) {
        int i = lista->tam - 1;
        while (i >= 0 && lista->n[i] > valor) {
            lista->n[i + 1] = lista->n[i];
            i--;
        }
        lista->n[i + 1] = valor;
        lista->tam++;
    }
}

//print iterativo
void imprimir(Lista *lista) {
    if (lista != NULL) {
        for (int i = 0; i < lista->tam; i++) {
            printf("%d ", lista->n[i]);
        }
        printf("\n");
    }
}

//função de busca binária recursiva
int buscaBinariaRecursiva(Lista *lista, int valor, int esq, int dir) {
    if (esq <= dir) {
        int meio = esq + (dir - esq) / 2;
        if (lista->n[meio] == valor) {
            return meio;
        } else if (lista->n[meio] < valor) {
            return buscaBinariaRecursiva(lista, valor, meio + 1, dir);
        } else {
            return buscaBinariaRecursiva(lista, valor, esq, meio - 1);
        }
    }
    return -1; 
}

//print recursivo
void imprimirRecursivo(Lista *lista, int index) {
    if (index < lista->tam) {
        printf("%d ", lista->n[index]);
        imprimirRecursivo(lista, index + 1);
    }
}

//função para buscar o maior elemento em uma lista (algoritmo recursivo)
int buscaMaiorRecursivo(Lista *lista, int index, int maior) {
    if (index < lista->tam) {
        if (lista->n[index] > maior) {
            maior = lista->n[index];
        }
        return buscaMaiorRecursivo(lista, index + 1, maior);
    }
    return maior;
}

//função para buscar o menor elemento em uma lista (algoritmo recursivo)
int buscaMenorRecursivo(Lista *lista, int index, int menor) {
    if (index < lista->tam) {
        if (lista->n[index] < menor) {
            menor = lista->n[index];
        }
        return buscaMenorRecursivo(lista, index + 1, menor);
    }
    return menor;
}

//função para retornar a soma da lista (algoritmo recursivo)
int retornarSomaRecursiva(Lista *lista, int index, int soma) {
    if (index < lista->tam) {
        soma += lista->n[index];
        return retornarSomaRecursiva(lista, index + 1, soma);
    }
    return soma;
}

//função para retornar o produto da lista (algoritmo recursivo)
int retornarProdutoRecursivo(Lista *lista, int index, int produto) {
    if (index < lista->tam) {
        produto *= lista->n[index];
        return retornarProdutoRecursivo(lista, index + 1, produto);
    }
    return produto;
}
