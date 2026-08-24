#include <stdio.h>

int main()
{
    struct Pessoa
    {
        char nome[50];
        int idade;
        float altura,peso;
    };

    struct Pessoa pessoa1 = {"João", 25,1.75,70.5};


    printf("Nome: %s\n", pessoa1.nome);
    printf("Idade: %d\n", pessoa1.idade);
    printf("Altura: %.2f\n", pessoa1.altura);
    printf("Peso: %.2f\n", pessoa1.peso);

}