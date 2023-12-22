#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "pilha.h"

int main() {
    Pilha hangar;
    inicializarPilha(&hangar);

    // Exemplo de uso
    adicionarAviao(&hangar, 1, "Aviao 1");
    adicionarAviao(&hangar, 2, "Aviao 2");
    adicionarAviao(&hangar, 3, "Aviao 3");

    listarAvioesHangar(&hangar);
    listarPrimeiroAviao(&hangar);

    removerAviao(&hangar);

    listarAvioesHangar(&hangar);

    removerAviaoPosicao(&hangar, 2);

    listarAvioesHangar(&hangar);

    return 0;
}