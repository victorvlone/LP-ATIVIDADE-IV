#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

float mediaSalarial(float salarios[]) {
    int i;
    float soma = 0;
    for (i = 0; i < 3; i++) {
        soma += salarios[i];
    }

    return soma / 3;
}

struct funcionario {
    char nome[999];
    char cargo[3][500];
    float salario;
};

int main() {
    setlocale(LC_ALL, "portuguese");

    int i;
    struct funcionario funcionarios[3];

    strcpy(funcionarios[0].cargo[0], "programador");
    strcpy(funcionarios[1].cargo[0], "programador");
    strcpy(funcionarios[2].cargo[0], "programador");

    for (i = 0; i < 3; i++) {
        printf("Dados do %dº %s\n", i + 1, funcionarios[i].cargo[0]);

        fflush(stdin);
        printf("Nome: ");
        gets(funcionarios[i].nome);
        printf("Salario: ");
        scanf("%f", &funcionarios[i].salario);
        fflush(stdin);
        system("cls || clear");
    }

    float salarios[3];
    for (i = 0; i < 3; i++) {
        salarios[i] = funcionarios[i].salario;
    }

    printf("Média salarial dos programadores: R$%.2f\n", mediaSalarial(salarios));

    return 0;
}
