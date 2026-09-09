#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa
{
    char nome[100];
    int idade;
} PESSOA;

int main()
{
    PESSOA *pPessoas = (PESSOA *)malloc(5 * sizeof(PESSOA));

    PESSOA cadastroInicial[5] = {
        {"Joana", 30},
        {"Carlos", 25},
        {"Mariana", 28},
        {"Pedro", 35},
        {"Ana", 22}
    };

    FILE *pCadastro;
    pCadastro = fopen("cadastro.txt", "w");

    for (int i = 0; i < 5; i++) {
        fprintf(pCadastro, "%s\n%d\n", cadastroInicial[i].nome, cadastroInicial[i].idade);
    }

    fclose(pCadastro);

    pCadastro = fopen("cadastro.txt", "r");

    for (int i = 0; i < 5; i++) {
        fscanf(pCadastro, " %99[^\n]\n%d", pPessoas[i].nome, &pPessoas[i].idade);
    }

    fclose(pCadastro);

    for (int i = 0; i < 5; i++) {
        printf("Nome: %s\n", pPessoas[i].nome);
        printf("Idade: %d\n\n", pPessoas[i].idade);
    }

    free(pPessoas);


    return 0;
}