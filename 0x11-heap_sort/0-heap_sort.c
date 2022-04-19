#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * linear_skip - Linear search in a skip list
 *
 * @list: Pointer to the head node of the list
 * @value: value to check
 * Return:0
 */
void swap(int *a, int *b) {
int temp = *a;
*a = *b;
*b = temp;
}
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
