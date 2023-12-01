#ifndef LISTA_LIGADA_ALUNO_H
#define LISTA_LIGADA_ALUNO_H

#define MAX_ALUNOS 100

typedef struct {
    int matricula;
    char nome[50];
    int idade;
} Aluno;

typedef struct {
    Aluno elementos[MAX_ALUNOS];
    int quantidade;
} ListaLigadaAlunos;

void inicializarLista(ListaLigadaAlunos *lista);
void liberarLista(ListaLigadaAlunos *lista);
int quantidadeElementos(ListaLigadaAlunos *lista);
int listaCheia(ListaLigadaAlunos *lista);
int listaVazia(ListaLigadaAlunos *lista);
void exibirLista(ListaLigadaAlunos *lista);
void inserirElemento(ListaLigadaAlunos *lista, Aluno aluno);
void excluirElemento(ListaLigadaAlunos *lista, int matricula);
void alterarMatricula(ListaLigadaAlunos *lista, int matriculaAntiga, int matriculaNova);

#endif
