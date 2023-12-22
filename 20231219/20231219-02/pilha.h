#ifndef PILHA_H
#define PILHA_H
#define MAX_AVIOES 100

typedef struct {
    int identificador;
    char nome[50];
} Aviao;

typedef struct {
    Aviao avioes[MAX_AVIOES];
    int topo;
} Pilha;

void inicializarPilha(Pilha* pilha); 
int pilhaVazia(const Pilha* pilha);
int pilhaCheia(const Pilha* pilha);
void adicionarAviao(Pilha* pilha, int identificador, const char* nome);
void listarAvioesHangar(const Pilha* pilha);   
void listarPrimeiroAviao(const Pilha* pilha);    
void removerAviao(Pilha* pilha); 
void removerAviaoPosicao(Pilha* pilha, int posicao);   

#endif