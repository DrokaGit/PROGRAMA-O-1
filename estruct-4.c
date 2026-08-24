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


    jose.idade = 25;
    jose.altura = 1.75;
    jose.peso = 70.5;
    strcpy(jose.nome,"João");

        printf("Nome: %s\n", jose.nome);
        printf("Idade: %d\n", jose.idade);
        printf("Peso:  %.2f\n", jose.peso);
        printf("Altura: %.2f\n \n", jose.altura);

}