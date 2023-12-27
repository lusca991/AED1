#ifndef PREFIX_H
#define PREFIX_H

typedef struct {
    char* expressao;
} ExpressaoInfixa;

typedef struct {
    char *dados;
    int topo;
    int capacidade;
} Pilha;

ExpressaoInfixa* criarExpressao(const char* expressao);
void apagarExpressao(ExpressaoInfixa* expressao);
void imprimirExpressao(const ExpressaoInfixa* expressao);
void infixa_to_prefixa(ExpressaoInfixa *infixa, char *prefixa);
int calcula_prefixa(char *prefixa);

#endif
