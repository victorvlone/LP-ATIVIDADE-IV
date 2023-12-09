#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

void resultado(float media){

    if (media >= 7){
        printf("situação: APROVADO!");
    } else {
        printf("situação: REPORVADO!");
    }
    
}

float calcularMedia (float soma){
  return soma / 2;  
}

struct Aluno{
    char nome [500];
    char datadeNascimento[500];
    float notas[2];
    float media;

};

int main () {

    setlocale(LC_ALL, "portuguese");

    int i, j, soma;
    struct Aluno aluno[5];

    for (i = 0; i < 5; i++){

        soma = 0;
        printf("DADOS DO %dº ALUNO\n\n", i+1);
        printf("Nome: ");
        gets(aluno[i].nome);
        printf("Data de nascimento: ");
        gets(aluno[i].datadeNascimento);

        for (j = 0;j < 2; j++){

            printf("%dª nota: ", j+1);
            scanf("%f", &aluno[i].notas[j]);
            soma += aluno[i].notas[j];

        }
        fflush(stdin);

        aluno[i].media = calcularMedia(soma);
        system("cls || clear");

    }

    for (i = 0; i < 5; i++){
        printf("\n\nNome: %s\n", aluno[i].nome);
        printf("Data de nascimento: %s\n", aluno[i].datadeNascimento);
        printf("Média: %.1f\n", aluno[i].media);
        resultado(aluno[i].media);
    }     
    
    return 0;
}
