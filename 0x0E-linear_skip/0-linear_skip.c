#include <stdio.h>
#include <stdlib.h>
#include "search.h"

/**
*
* linear_skip - Linear skip
* @list: list to check
* @value: the value to found
*
* Return: 0
*/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
skiplist_t *copy;
skiplist_t *p;
if (list == NULL)
return (NULL);
copy = list->express;
p = list;
while (copy != NULL)
{
printf("Value checked at index [%lu] = [%d]\n", copy->index, copy->n);
if (copy->n >= value)
break;
p = copy;
if (copy->express == NULL)
{
while (copy->next)
copy = copy->next;
break;
}
copy = copy->express;
}
printf("Value found between indexes [%lu] and [%lu]\n", 
p->index, copy->index);
while (p && p->index <= copy->index)
{
printf("Value checked at index [%lu] = [%d]\n", p->index, p->n);
if (p->n == value)
return (p);
p = p->next;
}
return (NULL);
}
