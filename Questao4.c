#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

float saldoAtual(float saldoAnterior, float deposito, float saque){
    return saldoAnterior + deposito - saque;
}

struct ContaBancaria{
    
    char nome[500];
    int numero;
    float saldo;
    char tipodeConta[500];

};

int main () {

    setlocale(LC_ALL, "portuguese");
    struct ContaBancaria conta;
    int resposta;
    float deposito, soma = 0, subtracao = 0, saque;

    printf("Nome do titular: ");
    gets(conta.nome);
    printf("Número da conta: ");
    scanf("%d", &conta.numero);
    printf("Saldo: ");
    scanf("%f", &conta.saldo);
    system("cls || clear");

    fflush(stdin);
    printf("Tipos de conta\n\n");
    printf("1. Poupança  ");
    printf("2. Corrente\n\n");
    printf("Qual é a sua? ");
    gets(conta.tipodeConta);
    system("cls || clear");

    printf("1. Depositar  ");
    printf("2. Sacar  ");
    printf("3. Imprimir o saldo atual\n\n");

    printf("como deseja prosseguir? ");
    scanf("%d", &resposta);
    system("cls || clear");

    while (resposta != 3){
        
        if (resposta == 1){

            printf("Quanto deseja depositar? ");
            scanf("%f", &deposito);
            soma += deposito;
            system("cls || clear");

            printf("1. Depositar  ");
            printf("2. Sacar  ");
            printf("3. Imprimir o saldo atual\n\n");

            printf("como deseja prosseguir? ");
            scanf("%d", &resposta);
            system("cls || clear");

        } else if (resposta == 2){

            printf("Quanto deseja sacar? ");
            scanf("%f", &saque);
            subtracao += saque;

            printf("1. Depositar  ");
            printf("2. Sacar  ");
            printf("3. Imprimir o saldo atual\n\n");

            printf("como deseja prosseguir? ");
            scanf("%d", &resposta);
            system("cls || clear");

        } else {
            printf("Opção desconhecida");
            getchar();
            resposta = 3;
            system("cls || clear");
        }
        
    }

    printf("Saldo Anterior: R$%.2f\n", conta.saldo);
    printf("Ttal de deposito: R$%.2f\n", soma);
    printf("Total de saque: R$%.2f\n\n", subtracao);
    printf("Saldo atual: R$%.2f\n", saldoAtual(conta.saldo, soma, subtracao));
    
    return 0;
}