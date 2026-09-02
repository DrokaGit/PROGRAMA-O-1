#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa
{
    char nome[50];
    int idade;
} PESSOA;

int main()
{
    PESSOA *pPessoa;

    pPessoa = malloc(sizeof *pPessoa);

    if (pPessoa == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    pPessoa->idade = 25;
    strcpy(pPessoa->nome, "Joao");

    printf("Nome: %s\n", pPessoa->nome);
    printf("Idade: %d\n", pPessoa->idade);

    free(pPessoa);
    pPessoa = NULL;

    return 0;
}