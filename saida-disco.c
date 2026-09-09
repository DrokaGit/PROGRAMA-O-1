#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct pessoa
{
    char nome[100];
    int idade;
} PESSOA;

int main()
{
    PESSOA *pPessoa;

    pPessoa = (PESSOA *)malloc(sizeof(PESSOA));

    strcpy(pPessoa->nome, "Joao");
    pPessoa->idade = 30;

    FILE *pCadastro;
    pCadastro = fopen("cadastro.txt", "w");

    fprintf(pCadastro, "Nome: %s\n", pPessoa->nome);
    fprintf(pCadastro, "Idade: %d\n", pPessoa->idade);

    fclose(pCadastro);
    free(pPessoa);


    return 0;
}