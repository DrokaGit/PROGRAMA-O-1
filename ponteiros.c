#include <stdio.h>


int main()
{
    int a;  // Nome para a posição da variavel que vai armazenar dados
    a = 10; // Valor para a variavel acima
    int *p; // nome á posição de memoria que vai armazenar o endereço da variavel A
    p = &a; // Extração do endereço da variavel A

    // o "&" nesse caso serve para pegar o endereço da variável "a"
    // "*pa" = o CONTEUDO do PONTEIRO(endereço) da VARIAVEL A. Nesse caso, o 10.
    printf("Valor de a: %d\n", a);
    printf("Endereço de a: %p\n", (void*)&a);

    *p = 20; // Mudei o valor da posição de memoria apontada para 20
    printf("Valor de p (endereço de a): %p\n", (void*)p);
    printf("Valor apontado por p: %d\n", *p);

    return 0;

}