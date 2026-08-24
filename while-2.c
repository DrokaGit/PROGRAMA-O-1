#include <stdio.h>

int main()
{
   int x = 10;
   int y = 20;
   

   while ((x < 15) || (y != x))
   {
        printf("x = %d, y = %d\n", x, y);
        x++;
   }

   return 0;
}