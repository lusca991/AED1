#include "lista_ligada_estatica2.h"
#include <stdio.h>

int main() {
    ListaLigadaEstatica lista1, lista2;
    inicializarLista(&lista1);
    inicializarLista(&lista2);


    printf("Lista 1 Original:\n");
    exibirLista(&lista1);

    printf("\nLista 2 Original:\n");
    exibirLista(&lista2);

    copiarLista(&lista2, &lista1);
    printf("\nLista 2 após cópia de Lista 1:\n");
    exibirLista(&lista2);

    concatenarListas(&lista1, &lista2);
    printf("\nLista 1 após concatenação com Lista 2:\n");
    exibirLista(&lista1);

    ListaLigadaEstatica listaInter;
    inicializarLista(&listaInter);
    intercalarListas(&lista1, &lista2);
    printf("\nLista intercalada de Lista 1 e Lista 2:\n");
    exibirLista(&lista1);

    return 0;
}
