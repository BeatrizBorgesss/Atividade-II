#include <stdio.h>
#include <string.h>

#define MAX 5

typedef struct {
    char nome[50];
    int idade;
} Pessoa;

typedef struct {
    Pessoa pessoas[MAX];
    int quantidade;
} Fila;

void adicionarPessoa(Fila *f, Pessoa p) {

    if(p.idade > 65) {

        for(int i = f->quantidade; i > 0; i--) {
            f->pessoas[i] = f->pessoas[i - 1];
        }

        f->pessoas[0] = p;

    } else {

        f->pessoas[f->quantidade] = p;
    }

    f->quantidade++;
}

int main() {

    Fila fila;
    fila.quantidade = 0;

    adicionarPessoa(&fila, (Pessoa){"Maria", 30});
    adicionarPessoa(&fila, (Pessoa){"Joao", 25});
    adicionarPessoa(&fila, (Pessoa){"Carlos", 70});
    adicionarPessoa(&fila, (Pessoa){"Ana", 20});
    adicionarPessoa(&fila, (Pessoa){"Jose", 80});

    printf("Fila de atendimento:\n\n");

    for(int i = 0; i < fila.quantidade; i++) {

        printf("Nome: %s\n", fila.pessoas[i].nome);
        printf("Idade: %d\n\n", fila.pessoas[i].idade);
    }

    return 0;
}
