#include <stdio.h>

int main()
{
    struct Pessoa
    {
        char nome[50];
        int idade;
        float altura,peso;
    };

    struct Pessoa joao;

    strcpy(joao.nome, "João");
    joao.idade  = 25;
    joao.altura = 1.75;
    joao.peso   = 70.5;

    struct Pessoa flavio;

    strcpy(flavio.nome, "Flávio");
    flavio.idade  = 54;
    flavio.altura = 1.85;
    flavio.peso   = 90.5;


    printf("Nome: %s\n", joao.nome);
    printf("Idade: %d\n", joao.idade);
    printf("Altura: %.2f\n", joao.altura);
    printf("Peso: %.2f\n \n \n", joao.peso);


    printf("Nome: %s\n", flavio.nome);
    printf("Idade: %d\n", flavio.idade);
    printf("Altura: %.2f\n", flavio.altura);
    printf("Peso: %.2f\n", flavio.peso);
    
    

}