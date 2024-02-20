#include <stdio.h>
#include "ArvRN.h"


int main() {
    ArvoreRubroNegra *arvore = criarArvore();

    inserir(arvore, 10);
    inserir(arvore, 20);
    inserir(arvore, 30);
    inserir(arvore, 15);
    inserir(arvore, 25);
    inserir(arvore, 5);
    inserir(arvore, 35);

    imprimirArvore(arvore);

    remover(arvore, 20);

    imprimirArvore(arvore);

    No *busca = buscar(arvore, 15);
    if (busca != NULL)
        printf("Elemento encontrado: %d\n", busca->chave);
    else
        printf("Elemento não encontrado\n");

    // Destruir a árvore
    destruirArvore(arvore);

    return 0;
}
   
