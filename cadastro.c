#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Pessoa
    {
        char nome[50];
        int idade;

    }PESSOA;

typedef struct nodo
    {
        struct nodo *pProximo;
        struct nodo *pAnterior;
        PESSOA *pPessoa;

    }NODO;

NODO *pInicio = NULL;
NODO *pFim = NULL;
NODO *pAtual = NULL;

NODO *CriaNodo(void);
PESSOA *CriaPessoa(void);
void CadastraPessoa(PESSOA *pPessoa);
void ImprimeCadastro(void);
void MainMenu(void);

// Cria e retorna uma area de memoria para uma pessoa.
PESSOA *CriaPessoa (void)
{
    return malloc(sizeof(PESSOA));

}

// Cria um no e inicializa seus ponteiros.
NODO *CriaNodo (void)
{
    NODO *pNodo = malloc(sizeof(NODO));

    if (pNodo != NULL)
    {
        pNodo->pProximo = NULL;
        pNodo->pAnterior = NULL;
        pNodo->pPessoa = NULL;
    }

    return pNodo;
}
// Cadastra o nome e a idade informados pelo usuario.
void CadastraPessoa (PESSOA *pPessoa)
{
    printf("Nome: ");
    scanf(" %49[^\n]", pPessoa->nome);
    printf("Idade: ");
    scanf("%d", &pPessoa->idade);

}
// Percorre a lista e imprime os cadastros.
void ImprimeCadastro(void)
{
    NODO *pNodo = pInicio;

    if (pNodo == NULL)
    {
        printf("\nNenhuma pessoa cadastrada.\n");
        return;
    }

    while (pNodo != NULL)
    {
        printf("\nNome: %s\n", pNodo->pPessoa->nome);
        printf("Idade: %d\n", pNodo->pPessoa->idade);
        pNodo = pNodo->pProximo;
    }
}
// Exibe o menu e executa a opcao escolhida.
void MainMenu(void)
{
    int opcao;

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
                pAtual = CriaNodo();

                if (pAtual == NULL || (pAtual->pPessoa = CriaPessoa()) == NULL)
                {
                    free(pAtual);
                    pAtual = NULL;
                    printf("\nNao foi possivel alocar memoria.\n");
                    break;
                }

                CadastraPessoa(pAtual->pPessoa);

                if (pFim == NULL)
                {
                    pInicio = pAtual;
                }
                else
                {
                    pFim->pProximo = pAtual;
                    pAtual->pAnterior = pFim;
                }
                pFim = pAtual;
                break;

            case 2:
                ImprimeCadastro();
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

// Inicia o programa e libera a memoria usada pela lista.
int main(void)
{
    MainMenu();

    while (pInicio != NULL)
    {
        pAtual = pInicio;
        pInicio = pInicio->pProximo;
        free(pAtual->pPessoa);
        free(pAtual);
    }

    return 0;
}