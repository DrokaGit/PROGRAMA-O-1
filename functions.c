#include <stdio.h>
#include <string.h>

void ImprimeCadastro(int quantidade);
void CadastroPessoa(int index);
void Menu();

typedef struct Pessoa
{
    char nome[50];
    int idade;
    float altura;
    float peso;
} PESSOA;

PESSOA cadastro[10];

int main()
{
    Menu();

    return 0;
}

void Menu()
{
    int opcao;
    int quantidade = 0;

    do
    {
        printf("\n------------------------------------------\n");
        printf(" 1: Cadastro de pessoa\n");
        printf(" 2: Imprimir cadastro de pessoas\n");
        printf(" 3: SAIR\n");
        printf("------------------------------------------\n");

        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:

                if (quantidade < 10)
                {
                    CadastroPessoa(quantidade);
                    quantidade++;

                    printf("\nPessoa cadastrada com sucesso!\n");
                }
                else
                {
                    printf("\nLimite de 10 pessoas atingido!\n");
                }

                break;

            case 2:

                if (quantidade == 0)
                {
                    printf("\nNenhuma pessoa cadastrada.\n");
                }
                else
                {
                    ImprimeCadastro(quantidade);
                }

                break;

            case 3:

                printf("\nSaindo do programa...\n");

                break;

            default:

                printf("\nOpcao invalida! Digite novamente.\n");

                break;
        }

    } while (opcao != 3);
}

void CadastroPessoa(int index)
{
    printf("\n--- Cadastro da pessoa %d ---\n", index + 1);

    printf("Nome: ");
    scanf(" %49[^\n]", cadastro[index].nome);

    printf("Idade: ");
    scanf("%d", &cadastro[index].idade);

    printf("Altura: ");
    scanf("%f", &cadastro[index].altura);

    printf("Peso: ");
    scanf("%f", &cadastro[index].peso);
}

void ImprimeCadastro(int quantidade)
{
    int index;

    printf("\n========== CADASTROS ==========\n");

    for (index = 0; index < quantidade; index++)
    {
        printf("\nPessoa %d\n", index + 1);

        printf("Nome: %s\n", cadastro[index].nome);
        printf("Idade: %d anos\n", cadastro[index].idade);
        printf("Altura: %.2f m\n", cadastro[index].altura);
        printf("Peso: %.2f kg\n", cadastro[index].peso);
    }

    printf("\n===============================\n");
}