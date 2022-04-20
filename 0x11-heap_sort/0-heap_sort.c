#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - Swap two ponters
 *
 * @a: Pointer
 * @b: Pointer
 * Return:0
 */
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}
/**
 * heapify - help the heap checking left and tight
 *
 * @array: the array
 * @n: the number
 * @i: the largest element
 * @size: the size of the tree
 * Return:0
 */
void heapify(int *array, int n, int i, size_t size)
{
int largest = i;
int left = 2 * i + 1;
int right = 2 * i + 2;
if (left < n && array[left] > array[largest])
largest = left;
if (right < n && array[right] > array[largest])
largest = right;
if (largest != i)
{
swap(&array[i], &array[largest]);
print_array(array, size);
heapify(array, n, largest, size);
}
}
/**
 * heap_sort - Heap sort
 *
 * @array: The array
 * @size: Size of the array
 * Return:0
 */
void heap_sort(int *array, size_t size)
{
int i = 0;
for (i = size / 2 ; i > 0; i--)
heapify(array, size, i - 1, size);
for (i = size - 1; i > 0; i--)
{
swap(&array[0], &array[i]);
print_array(array, size);
heapify(array, i, 0, size);
}
}
