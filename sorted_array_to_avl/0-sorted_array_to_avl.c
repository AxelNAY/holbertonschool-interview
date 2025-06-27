#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"


/**
 * sorted_array_to_avl - builds an AVL tree from an array
 *
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 *
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (merge_algo(array, 0, size - 1, NULL));
}

/**
 * merge_algo - a function that use recursion to sort the nodes of an
 * AVL tree from a sorted array
 *
 * @array: pointer to array containing elements
 *
 * @left_start: start of the left index
 *
 * @right_end: end of the right index
 *
 * @root: pointer to the parent node which is NULL
 *
 * Return: newly created node and it's values
 */
avl_t *merge_algo(int *array, int left_start, int right_end, avl_t *root)
{
	int middle;
	avl_t *tree;

	if (left_start > right_end)
		return (NULL);

	/* step 1 */
	middle = (left_start + right_end) / 2;

	/* step 2 and 3*/
	tree = calloc(1, sizeof(avl_t));
	if (tree == NULL) /* step 4 */
		return (NULL);

	tree->parent = root; /* step 5 */
	/* step 6.. */
	tree->left = merge_algo(array, left_start, middle - 1, tree);
	tree->right = merge_algo(array, middle + 1, right_end, tree);
	tree->n = array[middle]; /* step 7 */

	return (tree);
}
