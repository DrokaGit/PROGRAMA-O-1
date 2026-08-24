#include <stdio.h>

int main()
{
    int matriz[4][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };


    for (int i = 0 ; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
          if (matriz[i][j] % 2 == 0 )
          {
            printf("%d ", matriz[i][j]);
          }
          else 
          {
            printf("- ");
          }
        }
        printf("\n");
    }

    
    

    return 0;
}