#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
* binary_tree_node - creates a binary tree node
*
* @parent: Pointer to the parent node of the node to create
* @value: Value to put in the new node
*
* Return: A pointer to the new node if Success or NULL if Fail
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *new = malloc(sizeof(binary_tree_t));

	if (new == NULL)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	return (new);
}
