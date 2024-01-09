#include "deque_soldado.h"
#include <stdio.h>
#include <stdlib.h>

Deque* criar_deque() {
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    deque->inicio = NULL;
    deque->fim = NULL;
    deque->tamanho = 0;
    return deque;
}

void destruir_deque(Deque* deque) {
    while (!vazia(deque)) {
        remover_inicio(deque);
    }
    free(deque);
}

int inserir_inicio(Deque* deque, Soldado x) {
    Node* novo_no = (Node*)malloc(sizeof(Node));
    if (novo_no == NULL) {
        return 0;  // Falha na alocação de memória
    }
    novo_no->soldado = x;
    novo_no->proximo = deque->inicio;
    novo_no->anterior = NULL;

    if (vazia(deque)) {
        deque->fim = novo_no;
    } else {
        deque->inicio->anterior = novo_no;
    }

    deque->inicio = novo_no;
    deque->tamanho++;
    return 1;
}

int inserir_fim(Deque* deque, Soldado x) {
    Node* novo_no = (Node*)malloc(sizeof(Node));
    if (novo_no == NULL) {
        return 0;  // Falha na alocação de memória
    }
    novo_no->soldado = x;
    novo_no->proximo = NULL;
    novo_no->anterior = deque->fim;

    if (vazia(deque)) {
        deque->inicio = novo_no;
    } else {
        deque->fim->proximo = novo_no;
    }

    deque->fim = novo_no;
    deque->tamanho++;
    return 1;
}

Soldado remover_inicio(Deque* deque) {
    if (vazia(deque)) {
        Soldado soldado_vazio = {0, "", ""};  // Soldado vazio para indicar deque vazio
        return soldado_vazio;
    }

    Node* no_removido = deque->inicio;
    Soldado soldado_removido = no_removido->soldado;

    deque->inicio = no_removido->proximo;
    if (deque->inicio == NULL) {
        deque->fim = NULL;
    } else {
        deque->inicio->anterior = NULL;
    }

    free(no_removido);
    deque->tamanho--;

    return soldado_removido;
}

Soldado remover_fim(Deque* deque) {
    if (vazia(deque)) {
        Soldado soldado_vazio = {0, "", ""};  // Soldado vazio para indicar deque vazio
        return soldado_vazio;
    }

    Node* no_removido = deque->fim;
    Soldado soldado_removido = no_removido->soldado;

    deque->fim = no_removido->anterior;
    if (deque->fim == NULL) {
        deque->inicio = NULL;
    } else {
        deque->fim->proximo = NULL;
    }

    free(no_removido);
    deque->tamanho--;

    return soldado_removido;
}

Soldado primeiro(Deque* deque) {
    if (vazia(deque)) {
        Soldado soldado_vazio = {0, "", ""};  // Soldado vazio para indicar deque vazio
        return soldado_vazio;
    }

    return deque->inicio->soldado;
}

Soldado ultimo(Deque* deque) {
    if (vazia(deque)) {
        Soldado soldado_vazio = {0, "", ""};  // Soldado vazio para indicar deque vazio
        return soldado_vazio;
    }

    return deque->fim->soldado;
}

int contar(Deque* deque) {
    return deque->tamanho;
}

int vazia(Deque* deque) {
    return deque->tamanho == 0;
}
