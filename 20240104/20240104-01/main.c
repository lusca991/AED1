#include <stdio.h>
#include "deque_soldado.h"

int main() {
    Deque* deque_soldados = criar_deque();

    Soldado s1 = {1, "Soldado A", "Grau A"};
    Soldado s2 = {2, "Soldado B", "Grau B"};
    Soldado s3 = {3, "Soldado C", "Grau C"};
    Soldado s4 = {4, "Soldado D", "Grau D"};
    Soldado s5 = {5, "Soldado E", "Grau E"};

    inserir_inicio(deque_soldados, s1);
    inserir_fim(deque_soldados, s2);
    inserir_fim(deque_soldados, s3);
    inserir_fim(deque_soldados, s4);
    inserir_fim(deque_soldados, s5);

    printf("Deque de soldados:\n");
    printf("Contagem: %d\n", contar(deque_soldados));

    printf("Primeiro soldado: %s\n", primeiro(deque_soldados).nome);
    printf("Último soldado: %s\n", ultimo(deque_soldados).nome);

    printf("Removendo do início: %s\n", remover_inicio(deque_soldados).nome);
    printf("Contagem: %d\n", contar(deque_soldados));

    printf("Removendo do fim: %s\n", remover_fim(deque_soldados).nome);
    printf("Contagem: %d\n", contar(deque_soldados));

    destruir_deque(deque_soldados);

    int n = 3;
    Deque* deque_josephus = criar_deque();



    destruir_deque(deque_josephus);

    return 0;
}
