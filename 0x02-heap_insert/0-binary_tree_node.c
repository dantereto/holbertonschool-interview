#include "binary_trees.h"

/**
* binary_tree_node - function that creates a binary tree node
* @parent: pointer to data structure binary_tree_t
* @value: integer with binary tree node value
* Return: return binary tree node
*/

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *new_btn = malloc(sizeof(binary_tree_t));

/* guard condtion */
if (new_btn == NULL)
{
return (NULL);
}
new_btn->n = value;
new_btn->parent = parent;
new_btn->left = NULL;
new_btn->right = NULL;

return (new_btn);
}