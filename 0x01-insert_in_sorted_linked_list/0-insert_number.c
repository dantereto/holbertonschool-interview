#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
#include <string.h>
/**
* insert_node - Insert a node on a sorted list
* @head: pointer to head of list
* @number: the value of the node
* Return: number of nodes
*/
listint_t *insert_node(listint_t **head, int number)
{
listint_t *new;
listint_t *current;
new = malloc(sizeof(listint_t));
if (new == NULL)
return (NULL);
new->n = number;
new->next = NULL;
if (*head == NULL)
*head = new;
else
{
current = *head;
if (current->next == NULL && current->n > number)
{
new->next = current;
current = new;
return (new);
}
while (current->next != NULL)
{
if (current->next != NULL && current->next->n > number)
{
new->next = current->next;
current->next = new;
return (new);
}
current = current->next;
}
current->next = new;
}
return (new);
    }
