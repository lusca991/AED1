#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prefix.h"

//QUESTAO A

ExpressaoInfixa* criarExpressao(const char* expressao) {
    ExpressaoInfixa* novaExpressao = (ExpressaoInfixa*)malloc(sizeof(ExpressaoInfixa));
    if (novaExpressao == NULL) {
        printf("Erro ao alocar memória para a expressão.\n");
        return NULL;
    }

    novaExpressao->expressao = strdup(expressao);

    return novaExpressao;
}

void apagarExpressao(ExpressaoInfixa* expressao) {
    if (expressao != NULL) {
        free(expressao->expressao);
        free(expressao);
    }
}

void imprimirExpressao(const ExpressaoInfixa* expressao) {
    if (expressao != NULL) {
        printf("Expressao Infixa: %s\n", expressao->expressao);
    }
}

//QUESTAO B

void inicializaPilha(Pilha *pilha, int capacidade) {
    pilha->dados = (char *)malloc(sizeof(char) * capacidade);
    pilha->topo = -1;
    pilha->capacidade = capacidade;
}

int pilhaVazia(Pilha *pilha) {
    return pilha->topo == -1;
}

int pilhaCheia(Pilha *pilha) {
    return pilha->topo == pilha->capacidade - 1;
}

void Empilha(Pilha *pilha, char elemento) {
    if (pilhaCheia(pilha)) {
        printf("Erro: pilha cheia.\n");
        return;
    }

    pilha->dados[++pilha->topo] = elemento;
}

char Desempilha(Pilha *pilha) {
    if (pilhaVazia(pilha)) {
        printf("Erro: pilha vazia.\n");
        return '\0';
    }

    return pilha->dados[pilha->topo--];
}

int eh_operador(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int precedencia(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else
        return 0;
}

void infixa_to_prefixa(ExpressaoInfixa* infixa, char* prefixa) {
    Pilha pilha;
    inicializaPilha(&pilha, strlen(infixa->expressao));

    int i, j;
    j = 0;

    for (i = strlen(infixa->expressao) - 1; i >= 0; i--) {
        char c = infixa->expressao[i];

        if (c == ' ' || c == '\n')
            continue;

        if (eh_operador(c)) {
            while (!pilhaVazia(&pilha) && precedencia(pilha.dados[pilha.topo]) > precedencia(c)) {
                prefixa[j++] = Desempilha(&pilha);
                prefixa[j++] = ' ';
            }

            Empilha(&pilha, c);
        } else if (c == ')') {
            Empilha(&pilha, c);
        } else if (c == '(') {
            while (!pilhaVazia(&pilha) && pilha.dados[pilha.topo] != ')') {
                prefixa[j++] = Desempilha(&pilha);
                prefixa[j++] = ' ';
            }

            if (!pilhaVazia(&pilha) && pilha.dados[pilha.topo] == ')')
                Desempilha(&pilha);  // Descarta o par�ntese de fechamento
        } else {
            prefixa[j++] = c;
            prefixa[j++] = ' ';
        }
    }

    while (!pilhaVazia(&pilha)) {
        prefixa[j++] = Desempilha(&pilha);
        prefixa[j++] = ' ';
    }

    prefixa[j] = '\0';

    //Inverter a string resultante
    int inicio = 0;
    int fim = strlen(prefixa) - 1;

    while (inicio < fim) {
        char temp = prefixa[inicio];
        prefixa[inicio] = prefixa[fim];
        prefixa[fim] = temp;

        inicio++;
        fim--;
    }
}
 
//QUESTAO C

int calcula_prefixa(char *prefixa) {
    Pilha pilha;
    int tamanho = strlen(prefixa);
    inicializaPilha(&pilha, tamanho);
    int i;

    for (i = tamanho - 1; i >= 0; i--) {
        char c = prefixa[i];

        if (isspace(c))
            continue;

        if (isdigit(c)) {
            Empilha(&pilha, c - '0');
        } else if (eh_operador(c)) {
            if (pilhaVazia(&pilha)) {
                printf("Errou: Pilha vazia\n");
                exit(EXIT_FAILURE);
            }
            int operand1 = Desempilha(&pilha);
            int operand2 = Desempilha(&pilha);

            int resultado;

            switch (c) {
                case '+':
                    resultado = operand1 + operand2;
                    break;
                case '-':
                    resultado = operand1 - operand2;
                    break;
                case '*':
                    resultado = operand1 * operand2;
                    break;
                case '/':
                    resultado = operand1 / operand2;
                    break;
            }

            Empilha(&pilha, resultado);
        }
    }

    if (pilhaVazia(&pilha)) {
        printf("Errou: Pilha vazia\n");
        exit(EXIT_FAILURE);
    }

    return Desempilha(&pilha);
}
