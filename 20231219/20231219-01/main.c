#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

int main() {
    Fila fila;
    inicializarFila(&fila);

    // Exemplo de uso
    adicionarAviao(&fila, 1, "Aviao 1");
    adicionarAviao(&fila, 2, "Aviao 2");
    adicionarAviao(&fila, 3, "Aviao 3");

    listarAvioesEspera(&fila);
    listarPrimeiroAviao(&fila);

    autorizarDecolagem(&fila);

    listarAvioesEspera(&fila);

    return 0;
}