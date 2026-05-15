#include <stdio.h>
#include <string.h>

#define MAX 5

typedef struct {
    char nome[50];
    char cpf[20];
    char dataNascimento[20];
    char motivo[20];
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

    Pessoa p1 = {"Maria", "111.111.111-11", "10/05/1990", "Reclamar"};
    Pessoa p2 = {"Joao", "222.222.222-22", "20/07/1985", "Elogiar"};
    Pessoa p3 = {"Ana", "333.333.333-33", "15/09/1998", "Reclamar"};
    Pessoa p4 = {"Carlos", "444.444.444-44", "01/01/1970", "Reclamar"};
    Pessoa p5 = {"Julia", "555.555.555-55", "25/03/2000", "Elogiar"};

    enqueue(&fila, p1);
    enqueue(&fila, p2);
    enqueue(&fila, p3);
    enqueue(&fila, p4);
    enqueue(&fila, p5);

    int reclamar = 0;
    int elogiar = 0;

    while (fila.inicio < fila.fim) {

        Pessoa removida = dequeue(&fila);

        if(strcmp(removida.motivo, "Reclamar") == 0) {
            reclamar++;
        } else {
            elogiar++;
        }
    }

    if(elogiar < reclamar) {
        printf("Na fila de hoje tivemos %d pessoas que vieram elogiar e %d para reclamar.\n", elogiar, reclamar);
    } else {
        printf("Na fila de hoje tivemos %d pessoas que vieram reclamar e %d para elogiar.\n", reclamar, elogiar);
    }

    return 0;
}
