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


//Prototipos das funcoes

NODO *CriaNodo(void);                   //cria um nodo e inicializa seus ponteiros, retorna um ponteiro para o nodo criado.
PESSOA *CriaPessoa(void);               //cria uma pessoa e retorna um ponteiro para ela.
void CadastraPessoa(PESSOA *pPessoa);   //cadastra os dados de uma pessoa. //(PESSOA *pPessoa) passa o ponteiro para a pessoa que sera cadastrada.
void ImprimeCadastro(void);             //imprime os dados de todas as pessoas cadastradas.
void MainMenu(void);                    //exibe o menu e executa a opcao escolhida.
void CarregaCadastro(void);             //carrega as pessoas salvas no arquivo.
int SalvaPessoa(const PESSOA *pPessoa); //salva uma pessoa no arquivo.
int LimpaCadastro(void);                //apaga todos os cadastros da memoria e do arquivo.



// Cria e retorna uma area de memoria para uma pessoa.
void InsereNaLista(NODO *pNodo)
{
    if (pInicio == NULL)
    {
        pInicio = pNodo;
        pFim = pNodo;
        pAtual = pNodo;
    }
    else
    {
        pFim->pProximo = pNodo;
        pNodo->pAnterior = pFim;
        pFim = pNodo;

    }
    
}
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

// Le do arquivo as pessoas que ja estavam salvas.
void CarregaCadastro(void)
{
    FILE *arquivo = fopen("cadastro.txt", "r");
    char nome[50];
    int idade;

    if (arquivo == NULL)
    {
        return;
    }

    while (fscanf(arquivo, " %49[^\n]\n%d", nome, &idade) == 2)
    {
        NODO *pNodo = CriaNodo();

        if (pNodo == NULL)
        {
            break;
        }

        pNodo->pPessoa = CriaPessoa();
        if (pNodo->pPessoa == NULL)
        {
            free(pNodo);
            break;
        }

        strcpy(pNodo->pPessoa->nome, nome);
        pNodo->pPessoa->idade = idade;
        InsereNaLista(pNodo);
    }

    fclose(arquivo);
}

// Adiciona uma pessoa ao final do arquivo de cadastro.
int SalvaPessoa(const PESSOA *pPessoa)
{
    FILE *arquivo = fopen("cadastro.txt", "a");

    if (arquivo == NULL)
    {
        return 0;
    }

    fprintf(arquivo, "%s\n%d\n", pPessoa->nome, pPessoa->idade);
    fclose(arquivo);
    return 1;
}

// Remove todas as pessoas da lista e esvazia o arquivo de cadastro.
int LimpaCadastro(void)
{
    FILE *arquivo = fopen("cadastro.txt", "w");

    if (arquivo == NULL)
    {
        return 0;
    }

    fclose(arquivo);

    while (pInicio != NULL)
    {
        pAtual = pInicio;
        pInicio = pInicio->pProximo;
        free(pAtual->pPessoa);
        free(pAtual);
    }

    pFim = NULL;
    pAtual = NULL;
    return 1;
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
        printf(" 3: Limpar cadastro\n");
        printf(" 4: SAIR\n");
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

                InsereNaLista(pAtual);

                if (!SalvaPessoa(pAtual->pPessoa))
                {
                    printf("\nNao foi possivel salvar no arquivo.\n");
                }
                break;

            case 2:
                ImprimeCadastro();
                break;

            case 3:
                if (LimpaCadastro())
                {
                    printf("\nCadastro limpo com sucesso.\n");
                }
                else
                {
                    printf("\nNao foi possivel limpar o arquivo.\n");
                }
                break;

            case 4:
                printf("\nSaindo do programa...\n");
                break;

            default:
                printf("\nOpcao invalida! Digite novamente.\n");
                break;
        }

    } while (opcao != 4);
}

// Inicia o programa e libera a memoria usada pela lista.
int main(void)
{
    CarregaCadastro();
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