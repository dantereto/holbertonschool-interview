#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * rebuild - revuild the heap
 * @node : the node
 * Return: 0
 */

void rebuild(heap_t *node)
{
	int tmp;

	if (node->left == NULL)
		return;
	else if (node->right == NULL || node->left->n >= node->right->n)
	{
		if (node->n < node->left->n)
		{
			tmp = node->n;
			node->n = node->left->n;
			node->left->n = tmp;
		}
		rebuild(node->left);
	}
	else if (node->left->n < node->right->n)
	{
		if (node->n < node->right->n)
		{
			tmp = node->n;
			node->n = node->right->n;
			node->right->n = tmp;
		}
		rebuild(node->right);
	}
}

/**
 * heap_array - array for heap
 * @array: new array
 * @node: node
 * @index: the index
 * Return: 0
 */

void heap_array(heap_t **array, heap_t *node, int index)
{
	array[index] = node;
	if (node)
	{
		heap_array(array, node->left, (index * 2) + 1);
		heap_array(array, node->right, (index * 2) + 2);
	}
}

/**
 * tree_size - return size of tree
 * @root: root of tree
 * Return: 0
 */

int tree_size(heap_t *root)
{
	if (root == NULL)
		return (0);
	else
		return (tree_size(root->left) + 1 + tree_size(root->right));
}

/**
 * heap_extract - extract root node
 * @root: the rooz
 * Return: 0
 */

int heap_extract(heap_t **root)
{
	int size, n;
	heap_t **array;

	if (!root || !*root)
		return (0);
	n = (*root)->n;
	size = tree_size(*root);
	array = calloc(1024, sizeof(heap_t *));
	if (array == NULL)
		return (0);
	heap_array(array, *root, 0);
	if (array[size - 1] == *root)
	{
		free(array);
		free(*root);
		*root = NULL;
		return (n);
	}
	(*root)->n = array[size - 1]->n;
	if (array[size - 1]->parent->left == array[size - 1])
		array[size - 1]->parent->left = NULL;
	else
		array[size - 1]->parent->right = NULL;
	free(array[size - 1]);
	free(array);
	rebuild(*root);
	return (n);
}
