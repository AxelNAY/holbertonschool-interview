#include <stdlib.h>
#include <stdio.h>

#include "binary_trees.h"

/**
 * find_last_and_heapify - Find last node and restore heap property
 * @root: pointer to the root node
 * @index: current index (1-based)
 * @total: total number of nodes
 * @count_mode: if 1, count nodes; if 0, find last node
 * Return: pointer to the last node or count based on mode
 */
heap_t *find_last_and_heapify(heap_t *root, int index,
	int total, int count_mode)
{
	heap_t *left_result, *right_result, *largest;
	int temp;

	if (!root)
		return (count_mode ? (heap_t *)0 : NULL);

	if (count_mode)
		return ((heap_t *)(1 + (size_t)find_last_and_heapify(root->left, 0, 0, 1) +
							   (size_t)find_last_and_heapify(root->right, 0, 0, 1)));

	if (total > 0)
	{
		if (index == total)
			return (root);

		left_result = find_last_and_heapify(root->left, 2 * index, total, 0);
		if (left_result)
			return (left_result);

		right_result = find_last_and_heapify(root->right, 2 * index + 1, total, 0);
		return (right_result);
	}

	largest = root;
	if (root->left && root->left->n > largest->n)
		largest = root->left;
	if (root->right && root->right->n > largest->n)
		largest = root->right;

	if (largest != root)
	{
		temp = root->n;
		root->n = largest->n;
		largest->n = temp;
		find_last_and_heapify(largest, 0, -1, 0);
	}
	return (NULL);
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of the heap
 * Return: Value stored in the root node on success, 0 on failure
 */
int heap_extract(heap_t **root)
{
	int extracted_value, total_nodes;
	heap_t *last_node;

	if (!root || !*root)
		return (0);

	extracted_value = (*root)->n;

	if (!(*root)->left && !(*root)->right)
	{
		free(*root);
		*root = NULL;
		return (extracted_value);
	}

	total_nodes = (int)(size_t)find_last_and_heapify(*root, 0, 0, 1);
	last_node = find_last_and_heapify(*root, 1, total_nodes, 0);

	(*root)->n = last_node->n;

	if (last_node->parent)
	{
		if (last_node->parent->left == last_node)
			last_node->parent->left = NULL;
		else
			last_node->parent->right = NULL;
	}
	free(last_node);

	find_last_and_heapify(*root, 0, -1, 0);

	return (extracted_value);
}

/**
 * recurse_extract - Legacy function (kept for compatibility)
 * @tree: The pointer to the root of the tree
 */
void recurse_extract(heap_t *tree)
{
	heap_t *sub_max, *right_max = NULL;

	if (!tree->left)
		return;
	sub_max = max((tree)->left);
	if (tree->right)
		right_max = max(tree->right);
	if (right_max && right_max->n > sub_max->n)
		sub_max = right_max;
	tree->n = sub_max->n;
	if (!sub_max->left)
	{
		if (sub_max->parent && sub_max->parent->left == sub_max)
			sub_max->parent->left = NULL;
		if (sub_max->parent && sub_max->parent->right == sub_max)
			sub_max->parent->right = NULL;
		free(sub_max);
	}
	else
		recurse_extract(sub_max);
}

/**
 * max - Finds the maximum node in a tree
 * @tree: The pointer to the root of the tree
 * Return: The node with the maximum value
 */
heap_t *max(heap_t *tree)
{
	heap_t *curr_max, *left_max, *right_max;

	if (!tree->left)
		return (tree);
	left_max = max(tree->left);
	if (left_max->n > tree->n)
		curr_max = left_max;
	else
		curr_max = tree;
	if (tree->right)
	{
		right_max = max(tree->right);
		if (right_max->n > curr_max->n)
			curr_max = right_max;
	}
	return (curr_max);
}
