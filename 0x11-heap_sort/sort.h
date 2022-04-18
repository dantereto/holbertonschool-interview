#ifndef LIST_H_
#define LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void heap_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void heapify(int arr[], int n, int i);
void swap(int *a, int *b);

#endif