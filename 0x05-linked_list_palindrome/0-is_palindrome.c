#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - check if the linked list is a palindrome
 * @head: head of list
 * Return: 0
 */
int is_palindrome(listint_t **head)
{
    size_t i, siz;
    int array[1000];
    listint_t *temp;
    temp = *head;
    if (temp == NULL)
        return (1);
    else
    {
        for (siz = 0; temp != NULL; temp = temp->next, siz++)
            array[siz] = temp->n;
    }
    for(i = 0; i < siz / 2; i++)
    {
        if (array[i] != array[siz -i -1])
            return (0);
    }
    return (1);
}