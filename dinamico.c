#include <stdio.h>
#include <malloc.h>

int main()
{
    int *ptr;

    ptr = (int *)malloc(sizeof(int)*5);

    for(int i=0; i < 5; i++)
    {
        ptr[i] = 1;
    }

    for(int i=0; i < 5; i++)
    {
        printf("%d\n", ptr[1]);

    }

    free(ptr);
}