#include <stdio.h>
#include <stdlib.h>

/**
* insert_node - Insert a node on a sorted list
* @head: pointer to head of list
* @number: the value of the node
* Return: number of nodes
*/
int is_palindrome(unsigned long n)
{
    unsigned long i = 0, last, new;
    new = n;
    while (new != 0 )
    {
        last = new % 10;
        i = i * 10  + last;
        new = new / 10;
    }
    if (i == n)
        return (1);
    return (0);
}