#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * create_node - create binary tree node
 * @n: value of node
 * @point: the point
 *
 * Return: 0
 */
avl_t *create_node(int n, avl_t *point)
{
	avl_t *new = malloc(sizeof(*new));

	if (new == NULL)
		return (NULL);
	new->n = n;
	new->parent = point;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

/**
 * binary_traversal - traverse array in binary
 * @par: pointer to parent node
 * @a: array of values
 * @left: left index
 * @right: right index
 *
 * Return: 0
 */
avl_t *binary_traversal(avl_t *point, int *array, int left, int right)
{
	avl_t *new;
	int m;

	if (left > right)
		return (NULL);
	m = (left + right) / 2;
	new = create_node(array[m], point);
	if (!new)
		return (NULL);
	new->left = binary_traversal(new, array, left, m - 1);
	new->right = binary_traversal(new, array, m + 1, right);
	return (new);
}

/**
 * sorted_array_to_avl - sorted avl
 * @array: element of array
 * @size: size of array
 *
 * Return: 0
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	return (binary_traversal(NULL, array, 0, size - 1));
}