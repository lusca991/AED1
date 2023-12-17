#include <stdio.h>
#include "lista_ligada_dinamica2.h"

int main() {
    ListaLigadaDinamica lista;
    inicializarLista(&lista);

    printf("Inserindo elementos...\n");
    inserirElemento(&lista, 30);
    inserirElemento(&lista, 20);
    inserirElemento(&lista, 40);
    exibirLista(&lista);

    printf("\nPercorrendo e construindo L1a...\n");
    percorrerConstruirL1a(&lista);
    exibirLista(&lista);

    printf("\nPercorrendo e construindo L1b...\n");
    percorrerConstruirL1b(&lista);
    exibirLista(&lista);

    ListaLigadaDinamica lista2;
    inicializarLista(&lista2);
    inserirElemento(&lista2, 10);
    inserirElemento(&lista2, 50);

    printf("\nCopiando Lista para Lista2...\n");
    copiarLista(&lista2, &lista);
    exibirLista(&lista2);

    printf("\nConcatenando Lista1 com Lista2...\n");
    concatenarListas(&lista, &lista2);
    exibirLista(&lista);

    ListaLigadaDinamica lista3;
    inicializarLista(&lista3);
    inserirElemento(&lista3, 60);
    inserirElemento(&lista3, 70);

    printf("\nIntercalando Lista1 e Lista3...\n");
    intercalarListas(&lista, &lista3);
    exibirLista(&lista);

    return 0;
}
