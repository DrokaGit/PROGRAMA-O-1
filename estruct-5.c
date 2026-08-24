#include <stdio.h>
#include <string.h>


typedef struct Pessoa
    {
        char nome[50];
        int idade;
        float altura,peso;
    }PESSOA;




int main()
{   
        
     PESSOA jose;
     int opcao;

     
    do {


        printf("------------------------------------------ \n");
        printf(" 1: Cadastro de pessoa\n ");
        printf("2: Imprimir cadastro de pessoa\n ");
        printf("3: SAIR\n ");
        printf("------------------------------------------ \n");

        printf("Digite a opção desejada: ");
        int opcao;
        scanf("%d", &opcao);
        
        switch(opcao)
        {
        case 1: 
            printf("Nome: ");
            scanf("%s", jose.nome);
            printf("Idade: ");
            scanf("%d", &jose.idade);
            printf("Altura: ");
            scanf("%f", &jose.altura);
            printf("Peso: ");   
            scanf("%f", &jose.peso); 
            break;

        case 2: 
            printf("Nome: %s\n", jose.nome);
            printf("Idade: %d\n", jose.idade);
            printf("Peso:  %.2f\n", jose.peso);
            printf("Altura: %.2f\n \n", jose.altura);
            break;
        
        case 3: 
            printf("Saindo do programa... \n");

            break;
        default:
            printf("\n Opção inválida! Digite novamente.\n");
            break;
        }
    } while (opcao != 3);
   
    return 0;

}