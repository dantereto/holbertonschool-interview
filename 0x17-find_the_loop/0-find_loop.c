#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * find_listint_loop -fins the loop
 * @head: head of the list
 * Return: NULL.
 */
listint_t *find_listint_loop(listint_t *head)
{
listint_t *slow = head, *fast = head;
while (slow != '\0' && fast != '\0' && fast != '\0')
{
slow = slow->next;
fast = fast->next->next;
while (slow == fast)
{
slow = head;
while (slow != fast)
{
slow = slow->next;
fast = fast->next;
}
return (slow);
}
}
return ('\0');
}
