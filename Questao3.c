#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int EstoqueAtualizado(int QuantidadeInicial, int QuantidadeComprada){
    return QuantidadeInicial - QuantidadeComprada;
}

float TotalCompra(int quantidade, float preco){
    return preco * quantidade;
}

struct produto{
    
    char nome[999];
    float preco;
    int quantidade;
    
};

int main(){
    
    setlocale(LC_ALL, "portuguese");
    
    struct produto produtos[3];
    char resposta[500];
    int i, quantidadedeCompra[3];
    float precodoproduto;
    
    strcpy (produtos[0].nome, "arroz");
    strcpy (produtos[1].nome, "feijão");
    strcpy (produtos[2].nome, "carne");
    
    produtos[0].preco = 9.00;
    produtos[1].preco = 10.00;
    produtos[2].preco = 12.00;
    
    produtos[0].quantidade = 500;
    produtos[1].quantidade = 300;
    produtos[2].quantidade = 400;
    
    system("cls || clear");
    printf("1 - Realizar uma compra\n");
    printf("2 - Consultar estoque\n");
    printf("3 - Sair do programa\n\n"); 
    
    printf("Como deseja prosseguir? ");
    gets(resposta);
    
    while(strcmp(resposta, "sair do prgrama") != 0 && strcmp(resposta, "3") != 0){
        
        while(strcmp(resposta, "realizar uma compra") == 0 || strcmp(resposta, "1") == 0){
            
            printf("O que deseja comprar? ");
            gets(resposta);
            
            for(i = 0; i < 3; i++){
        
                if(strcmp(resposta, produtos[i].nome) == 0){
                    
                    printf("Preço do produto: R$%.2f\n", produtos[i].preco);
                    precodoproduto = produtos[i].preco;
                    printf("Quantos deseja comprar? ");
                    scanf("%d", &quantidadedeCompra);
                    printf("Valor total da compra: R$%.2f\n", TotalCompra(quantidadedeCompra[i], precodoproduto));
                    
                }
            }
            
            printf("Como deseja prosseguir? ");
            gets(resposta);
            
        }
        
        while(strcmp(resposta, "consultar estoque") == 0 || strcmp(resposta, "2") == 0){
            
            for(i = 0; i < 3; i++){
                
                printf("Nome do produto: %s\n", produtos[i].nome);
                printf("Preço do produto: R$%.2f\n", produtos[i].preco);
                printf("Quantidade em estoque: %d\n\n", EstoqueAtualizado(produtos[i].quantidade, quantidadedeCompra[i]));
            }
            getchar();
            strcpy(resposta, "3");
            
        }
        
    }
    
    return 0;
}
