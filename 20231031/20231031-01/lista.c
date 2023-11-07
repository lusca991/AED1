#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lista.h"
//função de criação da lista
Lista* criarLista(int tam){
    Lista *lista = (Lista*)malloc(sizeof(Lista));
    lista->tam=tam; 
    lista->n = (int*)malloc(sizeof(int) * tam);
    return lista;
}
//função free
void liberaLista(Lista *lista ){
    free (lista->n);
    free (lista);
}
//função de inserção de elemento
void inserirElemento (Lista *lista, int valor, int posicao){
    if (posicao >= 0 && posicao < lista->tam){
        lista->n[posicao] = valor;
    }
}
//print
void imprimir(Lista *lista){
    for(int i = 0; i < lista->tam; i++){
        printf("%d ", lista->n[i]);
    }
    printf("\n"); 
}

//busca sequencial
int buscaSequencial(Lista *lista, int valor){
    for (int i=0; i<lista->tam; i++){
        if (lista->n[i] == valor){
            return i;
        }
    }
}
//busca sequencial ordenada
int buscaS_Ordenada(Lista *lista, int valor){
    for (int i=0; i<lista->tam; i++){
        if (lista->n[i] == valor){
            return i;
        }
        if (lista->n[i] > valor)
        return -1;
    }
}
//busca binaria
int buscaBinaria(Lista *lista, int valor){
    int esq = 0;
    int dir = lista->tam -1;

    while (esq <= dir){
        int meio = esq +(dir - esq)/2;
        if(lista->n[meio] == valor){
            return meio;
        }
        if (lista->n[meio]<valor){
            esq = meio+1;
        } else{
            dir = meio-1;
        }
    }
    
    return -1;
}
//função pra buscar o maior elemento
int buscaMaior(Lista *lista){
    int maior = lista->n[0];
    for (int i = 1; i<lista->tam; i++){
        if (lista->n[i] > maior){
            maior=lista->n[i];
        }
    }
    return maior;
}
//função pra buscar o menor elemento
int buscaMenor(Lista *lista){
    int menor = lista->n[0];
    for (int i=1; i<lista->tam; i++){
        if (lista->n[i]<menor){
            menor=lista->n[i];
        }
    }
    return menor;
}
//função que faz a soma de todos os elementos da lista
int retornarSoma (Lista *lista){
    int soma=0;
    for (int i=0; i< lista->tam; i++){
        soma += lista->n[i];
    }
    return soma;
} 
//função que faz o produto de todos os elementos da lista
int retornarProduto(Lista *lista){
    int produto = 1;
    for(int i=0; i<lista->tam; i++){
        produto *= lista->n[i];
    }
    return produto;
}
//função q preenche os valores da lista
void preencherValores(Lista *lista) {
    for (int i = 0; i < lista->tam; i++) {
        printf("Digite o valor para a posicao %d: ", i);
        scanf("%d", &(lista->n[i]));
    }
}

//função para buscar um número na lista usando busca sequencial
int buscarNumeroSequencial(Lista *lista, int valor, int *comparacoes) {
    for (int i = 0; i < lista->tam; i++) {
        (*comparacoes)++; 
        if (lista->n[i] == valor) {
            return i+1; 
        }
    }
    return -1; 
}

//função para criar e preencher uma segunda lista ordenada
Lista* criarListaOrdenada(int tam) {
    Lista *lista = criarLista(tam);
    for (int i = 0; i < tam; i++) {
        lista->n[i] = i * 3; 
    }
    return lista;
}

//função para buscar um número na lista usando busca sequencial ordenada
int buscarNumeroSequencialOrdenada(Lista *lista, int valor, int *comparacoes) {
    for (int i = 0; i < lista->tam; i++) {
        (*comparacoes)++; 
        if (lista->n[i] == valor) {
            return i+1; 
        }
        if (lista->n[i] > valor) {
            return -1; 
        }
    }
    return -1; 
}

//função para buscar um número na lista usando busca binária interativa
int buscarNumeroBinariaIterativa(Lista *lista, int valor, int *comparacoes) {
    int esq = 0;
    int dir = lista->tam - 1;

    while (esq <= dir) {
        int meio = esq + (dir - esq) / 2;
        (*comparacoes)++; 
        if (lista->n[meio] == valor) {
            return meio; 
        }
        if (lista->n[meio] < valor) {
            esq = meio + 1;
        } else {
            dir = meio - 1;
        }
    }
    return -1;
}

//função para imprimir o maior elemento da lista
void imprimirMaior(Lista *lista) {
    int maior = buscaMaior(lista);
    printf("Maior elemento encontrado: %d\n", maior);
}

//função para imprimir o menor elemento da lista
void imprimirMenor(Lista *lista) {
    int menor = buscaMenor(lista);
    printf("Menor elemento encontrado: %d\n", menor);
}

//função para imprimir a soma dos elementos da lista
void imprimirSoma(Lista *lista) {
    int soma = retornarSoma(lista);
    printf("A soma de todos os elementos: %d\n", soma);
}

//função para imprimir o produto dos elementos da lista
void imprimirProduto(Lista *lista) {
    int produto = retornarProduto(lista);
    printf("O produto de todos os elementos: %d\n", produto);
}

//função para buscar um número na lista usando busca binária recursiva e contar as comparações
int buscarNumeroBinariaRecursiva(Lista *lista, int valor, int *comparacoes) {
    int esq = 0;
    int dir = lista->tam - 1;
    return buscaBinariaRecursivaAux(lista, valor, esq, dir, comparacoes);
}
//função auxiliar da função de cima
int buscaBinariaRecursivaAux(Lista *lista, int valor, int esq, int dir, int *comparacoes) {
    if (esq <= dir) {
        int meio = esq + (dir - esq) / 2;
        (*comparacoes)++; 
        if (lista->n[meio] == valor) {
            return meio; 
        }
        if (lista->n[meio] < valor) {
            return buscaBinariaRecursivaAux(lista, valor, meio + 1, dir, comparacoes);
        } else {
            return buscaBinariaRecursivaAux(lista, valor, esq, meio - 1, comparacoes);
        }
    }
    return -1; 
}


//função pra carajo 
//um adendo pro viana do futuro é usar essas como base e estudar elas regurlamente. (DEU TRABALHO DE FAZER TUDO ISSO E ENTENDER COMO CADA UMA FUNCIONA)//