#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - check if the linked list is a palindrome
 * @head: head of list
 * Return: 0
 */
int check_cycle(listint_t *list)
{
    listint_t *cont, *tail = list;
    cont = tail;
    if (list == NULL)
        return ('\0');
    while (cont && tail && tail->next)
    {
        cont = cont->next;
        tail = tail->next->next;
        if (cont == tail)
            return (1);
    }
    return (0);
}
