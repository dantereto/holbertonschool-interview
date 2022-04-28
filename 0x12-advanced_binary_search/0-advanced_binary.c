#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * advanced_binary - advanced binary
 *
 * @array: the array
 * @size: the size of the array
 * @value: the value of the array
 * Return:0
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t i = 1, j = 0, offset = 0;
	int tmp;

	if (array == NULL)
		return (-1);
	printf("Searching in array: %d", array[0]);
	while (i < size)
		printf(", %d", array[i++]);
	printf("\n");

	if (size == 1 && array[0] != value)
		return (-1);
	j = (size - 1) / 2;

	if (array[j] == value)
	{
		if (j == 0 || (array[j - 1] < value))
			return (j);
	}

	if (array[j] < value)
	{
		offset += j + 1;
		array += j + 1;
		if (size % 2 != 0)
			j--;
	}
	j++;
	tmp = advanced_binary(array, j, value);

	if (tmp != -1)
		return (tmp + offset);
	return (-1);
}
