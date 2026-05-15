#include <stdio.h>
#include <string.h>

#define MAX 5

typedef struct {
    int codigo;
    char arquivo[50];
    int bytes;
} Documento;

typedef struct {
    Documento docs[MAX];
    int inicio;
    int fim;
} Fila;

void iniciarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}

void enqueue(Fila *f, Documento d) {
    f->docs[f->fim] = d;
    f->fim++;
}

Documento dequeue(Fila *f) {
    Documento d = f->docs[f->inicio];
    f->inicio++;
    return d;
}

int main() {

    Fila fila;
    iniciarFila(&fila);

    enqueue(&fila, (Documento){1, "arquivo1.pdf", 500});
    enqueue(&fila, (Documento){2, "foto.png", 1200});
    enqueue(&fila, (Documento){3, "documento.docx", 800});
    enqueue(&fila, (Documento){4, "planilha.xlsx", 650});
    enqueue(&fila, (Documento){5, "atividade.txt", 300});

    while(fila.inicio < fila.fim) {

        Documento d = dequeue(&fila);

        printf("Codigo: %d\n", d.codigo);
        printf("Arquivo: %s\n", d.arquivo);
        printf("Quantidade de bytes: %d\n\n", d.bytes);
    }

    return 0;
}
