#include "lista_ligada_aluno.h"
#include <stdio.h>

void inicializarLista(ListaLigadaAlunos *lista) {
    lista->quantidade = 0;
}

void liberarLista(ListaLigadaAlunos *lista) {
    lista->quantidade = 0;
}

int quantidadeElementos(ListaLigadaAlunos *lista) {
    return lista->quantidade;
}

int listaCheia(ListaLigadaAlunos *lista) {
    return lista->quantidade == MAX_ALUNOS;
}

int listaVazia(ListaLigadaAlunos *lista) {
    return lista->quantidade == 0;
}

void exibirLista(ListaLigadaAlunos *lista) {
    printf("Lista de Alunos:\n");
    for (int i = 0; i < lista->quantidade; ++i) {
        printf("Matrícula: %d, Nome: %s, Idade: %d\n", lista->elementos[i].matricula,
               lista->elementos[i].nome, lista->elementos[i].idade);
    }
    printf("\n");
}

void inserirElemento(ListaLigadaAlunos *lista, Aluno aluno) {
    if (listaCheia(lista)) {
        printf("Erro: Lista cheia, impossível inserir.\n");
        return;
    }

    int i = lista->quantidade - 1;
    while (i >= 0 && lista->elementos[i].matricula > aluno.matricula) {
        lista->elementos[i + 1] = lista->elementos[i];
        i--;
    }

    lista->elementos[i + 1] = aluno;
    lista->quantidade++;
}

void excluirElemento(ListaLigadaAlunos *lista, int matricula) {
    if (listaVazia(lista)) {
        printf("Erro: Lista vazia, impossível excluir.\n");
        return;
    }

    int i = 0;
    while (i < lista->quantidade && lista->elementos[i].matricula != matricula) {
        i++;
    }

    if (i == lista->quantidade) {
        printf("Erro: Matrícula não encontrada, impossível excluir.\n");
        return;
    }

    for (int j = i; j < lista->quantidade - 1; ++j) {
        lista->elementos[j] = lista->elementos[j + 1];
    }

    lista->quantidade--;
}

void alterarMatricula(ListaLigadaAlunos *lista, int matriculaAntiga, int matriculaNova) {
    if (listaVazia(lista)) {
        printf("Erro: Lista vazia, impossível alterar.\n");
        return;
    }

    int i = 0;
    while (i < lista->quantidade && lista->elementos[i].matricula != matriculaAntiga) {
        i++;
    }

    if (i == lista->quantidade) {
        printf("Erro: Matrícula não encontrada, impossível alterar.\n");
        return;
    }

    lista->elementos[i].matricula = matriculaNova;
}
