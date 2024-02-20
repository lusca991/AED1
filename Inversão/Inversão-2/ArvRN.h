#ifndef ArvRB_H
#define ArvRB_H

typedef struct No {
    int chave;
    enum {VERMELHO, PRETO} cor;
    struct No *esquerda, *direita, *pai;
} No;

typedef struct ArvoreRubroNegra {
    No *raiz;
} ArvoreRubroNegra;

ArvoreRubroNegra* criarArvore();
void destruirArvore(ArvoreRubroNegra *arvore);
No* buscar(ArvoreRubroNegra *arvore, int chave);
void inserir(ArvoreRubroNegra *arvore, int chave);
void remover(ArvoreRubroNegra *arvore, int chave);
void rotacaoEsquerda(ArvoreRubroNegra *arvore, No *x);
void rotacaoDireita(ArvoreRubroNegra *arvore, No *x);
void verificarInsercao(ArvoreRubroNegra *arvore, No *z);
void verificarRemocao(ArvoreRubroNegra *arvore, No *x);
void corrigirInsercao(ArvoreRubroNegra *arvore, No *z);
void corrigirRemocao(ArvoreRubroNegra *arvore, No *x);
int cor(No *x);
No* irmao(No *x);
No* tio(No *x);
No* minimo(No *x);
void transplantar(ArvoreRubroNegra *arvore, No *u, No *v);
void balancear(ArvoreRubroNegra *arvore, No *x);
void imprimirEmOrdem(No *raiz);
void imprimirArvore(ArvoreRubroNegra *arvore);

#endif
    