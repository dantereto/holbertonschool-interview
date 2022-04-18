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
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
}
void heap_sort(int *array, size_t size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
      heapify(arr, size, i);
    for (int i = n - 1; i >= 0; i--) 
    {
      swap(&array[0], &array[i]);
    heapify(arr, i, 0);
    }
}