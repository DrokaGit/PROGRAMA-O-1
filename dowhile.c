#include <stdio.h>

int main()
{
    int i = 0;
    int lista[5];

    do 
    {
        lista[i] = i + 10;
        i++;

    } while (i < 5);


    i = 0;
    do
    {
        printf("lista[%d] = %d\n", i , lista[i]);
        i++;

    } while (i < 5);
    

    return 0;
}