#include "menger.h"
/**
* menger - print menger
* @level: level
* Return: 0
**/
void menger(int level)
{
    int size = pow(3, level);
    int i, j, k, m;
    char square;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            square = '#';
            k = i;
            for (m = j; m; m /= 3)
            {
                if (k % 3 == 1 && m % 3 == 1)
                square = ' ';
                k = k / 3;
            }
            printf("%c", square);
        }
    printf("\n");
    }
}
