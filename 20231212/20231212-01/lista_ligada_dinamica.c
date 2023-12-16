#include "lista_ligada_dinamica.h"
#include <stdio.h>
#include <stdlib.h>

void inicializarLista(ListaLigadaDinamica* lista) {
    lista->inicio = NULL;
    lista->quantidade = 0;
}

void reiniciarLista(ListaLigadaDinamica* lista) {
    while (lista->inicio != NULL) {
        Aluno* temp = lista->inicio;
        lista->inicio = lista->inicio->proximo;
        free(temp);
    }
    lista->quantidade = 0;
}

int quantidadeElementos(ListaLigadaDinamica* lista) {
    return lista->quantidade;
}

int listaCheia(ListaLigadaDinamica* lista) {
    return 0; 
}

int listaVazia(ListaLigadaDinamica* lista) {
    return lista->quantidade == 0;
}

void exibirLista(ListaLigadaDinamica* lista) {
    Aluno* atual = lista->inicio;
    printf("Lista de Alunos:\n");
    while (atual != NULL) {
        printf("Matrícula: %d, Nome: %s, Idade: %d\n", atual->matricula, atual->nome, atual->idade);
        atual = atual->proximo;
    }
    printf("\n");
}

Aluno* criarAluno(int matricula, const char* nome, int idade) {
  Aluno* novoAluno = (Aluno*)malloc(sizeof(Aluno));
  if (novoAluno == NULL) {
    return NULL;
  }

  novoAluno->matricula = matricula;
  snprintf(novoAluno->nome, sizeof(novoAluno->nome), "%s", nome);
  novoAluno->idade = idade;
  novoAluno->proximo = NULL;

  return novoAluno;
}

int inserirElemento(ListaLigadaDinamica* lista, int matricula, const char* nome, int idade) {
  Aluno* novoAluno = criarAluno(matricula, nome, idade);
  if (novoAluno == NULL) {
    return 0;
  }

  Aluno** atual = &lista->inicio;

  while (*atual != NULL && (*atual)->matricula < matricula) {
    atual = &((*atual)->proximo);
  }

  novoAluno->proximo = *atual;
  *atual = novoAluno;

  lista->quantidade++;

  return 1;
}

int excluirElemento(ListaLigadaDinamica* lista, int matricula) {
  Aluno** atual = &lista->inicio;

  while (*atual != NULL && (*atual)->matricula != matricula) {
    atual = &((*atual)->proximo);
  }

  if (*atual != NULL) {
    Aluno* temp = *atual;
    *atual = (*atual)->proximo;
    free(temp);
    lista->quantidade--;

    return 1;
  }

  return 0;
}
