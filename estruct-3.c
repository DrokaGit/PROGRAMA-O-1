#include <stdio.h>
#include <string.h>
int main()
{
    struct Pessoa
    {
        char nome[50];
        int idade;
        float altura,peso;
    };
    
    struct Pessoa pessoas[5];
    

    strcpy(pessoas[0].nome, "João");
    pessoas[0].idade  = 18;
    pessoas[0].altura = 1.87;
    pessoas[0].peso   = 78.3;

    strcpy(pessoas[1].nome, "Maria");
    pessoas[1].idade  = 50;
    pessoas[1].altura = 1.56;
    pessoas[1].peso   = 100.1;

    strcpy(pessoas[2].nome, "Carlos");
    pessoas[2].idade  = 23;
    pessoas[2].altura = 1.77;
    pessoas[2].peso   = 89.9;

    
    for (int i = 0; i < 3; i++)
    {
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Idade: %d\n", pessoas[i].idade);
        printf("Peso:  %.2f\n", pessoas[i].peso);
        printf("Altura: %.2f\n \n", pessoas[i].altura);
    }

}