#include <stdio.h>
#include <stdlib.h>

#define VAZIO -1

typedef struct {
    int* chaves;
    int tamanho;
} TabelaHashAberta;

TabelaHashAberta* criarTabelaHashAberta(int tamanho) {
    TabelaHashAberta* tabela = (TabelaHashAberta*)malloc(sizeof(TabelaHashAberta));
    tabela->tamanho = tamanho;
    tabela->chaves = (int*)malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++) {
        tabela->chaves[i] = VAZIO;
    }

    return tabela;
}

void inserirSondagemLinear(TabelaHashAberta* tabela, int chave, int* colisoes) {
    int i;
    for (i = 0; i < tabela->tamanho; i++) {
        int indice = (chave + i) % tabela->tamanho;
        if (tabela->chaves[indice] == VAZIO) {
            tabela->chaves[indice] = chave;
            return;
        } else {
            (*colisoes)++;
        }
    }
}

void inserirSondagemQuadratica1(TabelaHashAberta* tabela, int chave, int* colisoes) {
    int i;
    for (i = 0; i < tabela->tamanho; i++) {
        int indice = (chave + i * i) % tabela->tamanho;
        if (tabela->chaves[indice] == VAZIO) {
            tabela->chaves[indice] = chave;
            return;
        } else {
            (*colisoes)++;
        }
    }
}

void inserirSondagemQuadratica2(TabelaHashAberta* tabela, int chave, int* colisoes) {
    int i;
    for (i = 0; i < tabela->tamanho; i++) {
        int indice = (chave + 2 * i + i * i) % tabela->tamanho;
        if (tabela->chaves[indice] == VAZIO) {
            tabela->chaves[indice] = chave;
            return;
        } else {
            (*colisoes)++;
        }
    }
}

void inserirHashDuplo(TabelaHashAberta* tabela, int chave, int* colisoes) {
    int h1 = chave % tabela->tamanho;
    int h2 = 7 - (chave % 7);

    int i;
    for (i = 0; i < tabela->tamanho; i++) {
        int indice = (h1 + i * h2) % tabela->tamanho;
        if (tabela->chaves[indice] == VAZIO) {
            tabela->chaves[indice] = chave;
            return;
        } else {
            (*colisoes)++;
        }
    }
}

void imprimirTabelaHashAberta(TabelaHashAberta* tabela) {
    for (int i = 0; i < tabela->tamanho; i++) {
        printf("[%d]: ", i);
        if (tabela->chaves[i] != VAZIO) {
            printf("%d", tabela->chaves[i]);
        } else {
            printf("NULL");
        }
        printf("\n");
    }
}

int main() {
    int M = 11;

    TabelaHashAberta* tabelaLinear = criarTabelaHashAberta(M);
    TabelaHashAberta* tabelaQuadratica1 = criarTabelaHashAberta(M);
    TabelaHashAberta* tabelaQuadratica2 = criarTabelaHashAberta(M);
    TabelaHashAberta* tabelaDuplo = criarTabelaHashAberta(M);

    int chaves[] = {365, 112, 180, 213, 13, 27};
    int numChaves = sizeof(chaves) / sizeof(chaves[0]);

    int colisoesLinear = 0;
    int colisoesQuadratica1 = 0;
    int colisoesQuadratica2 = 0;
    int colisoesDuplo = 0;

    for (int i = 0; i < numChaves; i++) {
        inserirSondagemLinear(tabelaLinear, chaves[i], &colisoesLinear);
        inserirSondagemQuadratica1(tabelaQuadratica1, chaves[i], &colisoesQuadratica1);
        inserirSondagemQuadratica2(tabelaQuadratica2, chaves[i], &colisoesQuadratica2);
        inserirHashDuplo(tabelaDuplo, chaves[i], &colisoesDuplo);
    }

    printf("Tabela hash usando sondagem linear (Colisoes: %d):\n", colisoesLinear);
    imprimirTabelaHashAberta(tabelaLinear);

    printf("\nTabela hash usando sondagem quadratica (versao 1) (Colisoes: %d):\n", colisoesQuadratica1);
    imprimirTabelaHashAberta(tabelaQuadratica1);

    printf("\nTabela hash usando sondagem quadratica (versao 2) (Colisoes: %d):\n", colisoesQuadratica2);
    imprimirTabelaHashAberta(tabelaQuadratica2);

    printf("\nTabela hash usando hash duplo (Colisoes: %d):\n", colisoesDuplo);
    imprimirTabelaHashAberta(tabelaDuplo);

    free(tabelaLinear->chaves);
    free(tabelaLinear);

    free(tabelaQuadratica1->chaves);
    free(tabelaQuadratica1);

    free(tabelaQuadratica2->chaves);
    free(tabelaQuadratica2);

    free(tabelaDuplo->chaves);
    free(tabelaDuplo);

    return 0;
}
