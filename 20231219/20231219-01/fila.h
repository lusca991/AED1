#ifndef FILA_H
#define FILA_H
#define MAX_AVIOES 100

typedef struct {
    int identificador;
    char nome[50];
} Aviao;

typedef struct {
    Aviao avioes[MAX_AVIOES];
    int inicio;
    int fim;
    int tamanho;
} Fila;

void inicializarFila(Fila* fila);  
int filaVazia(const Fila* fila); 
int filaCheia(const Fila* fila); 
void adicionarAviao(Fila* fila, int identificador, const char* nome);
void listarAvioesEspera(const Fila* fila); 
void listarPrimeiroAviao(const Fila* fila); 
void autorizarDecolagem(Fila* fila);    


#endif