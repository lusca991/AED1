#ifndef LISTA_LIGADA_DINAMICA_H
#define LISTA_LIGADA_DINAMICA_H

typedef struct Aluno {
    int matricula;
    char nome[50];
    int idade;
    struct Aluno* proximo;
} Aluno;

typedef struct {
    Aluno* inicio;
    int quantidade;
} ListaLigadaDinamica;

Aluno* criarAluno(int matricula, const char* nome, int idade);
int inserirElemento(ListaLigadaDinamica* lista, int matricula, const char* nome, int idade);
int excluirElemento(ListaLigadaDinamica* lista, int matricula);
void inicializarLista(ListaLigadaDinamica* lista);
void reiniciarLista(ListaLigadaDinamica* lista);
int quantidadeElementos(ListaLigadaDinamica* lista);
int listaCheia(ListaLigadaDinamica* lista);
int listaVazia(ListaLigadaDinamica* lista);
void exibirLista(ListaLigadaDinamica* lista);


#endif
