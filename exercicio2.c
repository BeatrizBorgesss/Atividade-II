#include <stdio.h>
#include <string.h>

#define MAX 5

typedef struct {
    char nome[50];
    int tempo;
} Pessoa;

typedef struct {
    Pessoa pessoas[MAX];
    int inicio;
    int fim;
} Fila;

void iniciarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}

void enqueue(Fila *f, Pessoa p) {
    f->pessoas[f->fim] = p;
    f->fim++;
}

Pessoa dequeue(Fila *f) {
    Pessoa p = f->pessoas[f->inicio];
    f->inicio++;
    return p;
}

int main() {

    Fila fila;
    iniciarFila(&fila);

    enqueue(&fila, (Pessoa){"Maria", 10});
    enqueue(&fila, (Pessoa){"Joao", 7});
    enqueue(&fila, (Pessoa){"Ana", 9});
    enqueue(&fila, (Pessoa){"Carlos", 5});
    enqueue(&fila, (Pessoa){"Julia", 12});

    int soma = 0;
    int quantidade = 0;

    while(fila.inicio < fila.fim) {

        Pessoa p = dequeue(&fila);

        printf("Pessoa atendida: %s\n", p.nome);
        printf("Tempo de atendimento: %d minutos\n\n", p.tempo);

        soma += p.tempo;
        quantidade++;
    }

    float media = (float)soma / quantidade;

    printf("Media de atendimento: %.2f minutos\n", media);

    if(media > 8) {
        printf("Recomendado abrir um novo caixa.\n");
    } else {
        printf("Nao e necessario abrir um novo caixa.\n");
    }

    return 0;
}
