#include <stdio.h>
#include <stdlib.h>
#include "slide_line.h"

/**
 * slide_line - check if the linked list is a palindrome
 * @line: line of array
 * @size: nvalues
 * @direction: directiom of slide
 * Return: 0
 */
int slide_line(int *line, size_t size, int direction)
{
    int cont = -1;
    size_t posf = 0, posr = 0, i = 1, copy_s = size;

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);
	if (direction == SLIDE_RIGHT)
		posf = size - 1, posr = size - 1, i = -1, copy_s = -1;
	while (posf != copy_s)
	{
		if (*(line + posf) != 0)
		{
			if (cont == *(line + posf))
				*(line + posf) += cont, cont = -1;
			else
			{
				cont = *(line + posf);
				if ((direction == SLIDE_LEFT && posf != 0) ||
				   ((direction == SLIDE_RIGHT && posf != (size - 1))))
					if (*(line + posr) != 0)
						posr += i;
			}
			*(line + posr) = *(line + posf);
			if (posr != posf)
				*(line + posf) = 0;
		}
		posf += i;
	}
	return (1);
}