#include <stdlib.h>
#include <stdio.h>

/**
 * _isdigit -  checks for numbers
 *@c: the number
 *Return: return 0
 */
int _isdigit(char *n)
{
    int i;

    i = 0;
    while (*(n + i) != '\0')
    {
        if (*(n + i) < '0' || *(n + i) > '9')
            return (0);
        i++;
    }
    return (1);
}

/**
 * _strlen - checks the lenght of a string
 *@s: the string
 *Return: return 0
 */
int _strlen(char *s)
{
int cont = 0;
while (s[cont] != '\0')
{
cont++;
}
return (cont);
}
/**
 * rebuild - revuild the heap
 * @node : the node
 * Return: 0
 */

int main(int argc, char *argv[])
{
    int pointer, response, len, number, number2, i, j;
    int *total;
    if (argc < 3 || argc > 3 || !(_isdigit(argv[1])) || !(_isdigit(argv[2])))
    {
        printf("Error\n");
		exit(98);
    }
    if (argv[1][0] == '0' || argv[2][0] == '0')
    {
        printf("0\n");
        return (0);
    }
    number = _strlen(argv[1]), number2 = _strlen(argv[2]);
    len = number + number2;
    total = calloc(len, sizeof(int *));
    if (total == NULL)
    {
        printf("Error\n");
		exit(98);
    }
    for (i = (number2 - 1); i > -1; i--)
    {
        response = 0;
        for (j = (number - 1); j > -1; j--)
        {
            pointer = (argv[2][i] - '0') * (argv[1][j] - '0');
            response = (pointer / 10);
            total[(i + j) + 1] += (pointer % 10);
            if (total[(i + j) + 1] > 9)
            {
                total[i + j] += total[(i + j) + 1] / 10;
                total[(i + j) + 1] = total[(i + j) + 1] % 10;
            }
            total[(i + j)] += response;
        }
    }
    if (total[0] == 0)
        i = 1;
    else
        i = 0;
    for (; i < len; i++)
        printf("%d", total[i]);
    printf("\n");
    free(total);
    return (0);
}
