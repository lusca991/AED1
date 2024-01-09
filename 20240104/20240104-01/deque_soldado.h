#ifndef DEQUE_SOLDADO_H
#define DEQUE_SOLDADO_H

typedef struct Soldado {
    int codigo;
    char nome[50];
    char grau[20];
} Soldado;

typedef struct Node {
    Soldado soldado;
    struct Node* proximo;
    struct Node* anterior;
} Node;

typedef struct Deque {
    Node* inicio;
    Node* fim;
    int tamanho;
} Deque;

Deque* criar_deque();
void destruir_deque(Deque* deque);
int inserir_inicio(Deque* deque, Soldado x);
int inserir_fim(Deque* deque, Soldado x);
Soldado remover_inicio(Deque* deque);
Soldado remover_fim(Deque* deque);
Soldado primeiro(Deque* deque);
Soldado ultimo(Deque* deque);
int contar(Deque* deque);
int vazia(Deque* deque);

#endif
