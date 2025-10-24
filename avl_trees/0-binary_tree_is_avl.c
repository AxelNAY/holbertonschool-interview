#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "binary_trees.h"

/**
 * height - Measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the tree, 0 if tree is NULL
 */
int height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = height(tree->left);
	right_height = height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * is_avl_helper - Helper function to check if tree is AVL
 * @tree: pointer to the root node of the tree to check
 * @min: minimum value allowed in this subtree
 * @max: maximum value allowed in this subtree
 * Return: 1 if valid AVL, 0 otherwise
 */
int is_avl_helper(const binary_tree_t *tree, int min, int max)
{
	int left_height, right_height, balance;

	if (tree == NULL)
		return (1);

	/* Check BST property */
	if (tree->n <= min || tree->n >= max)
		return (0);

	/* Calculate heights */
	left_height = height(tree->left);
	right_height = height(tree->right);

	/* Calculate balance factor */
	balance = left_height - right_height;

	/* Check AVL property (balance factor must be -1, 0, or 1) */
	if (balance < -1 || balance > 1)
		return (0);

	/* Recursively check left and right subtrees */
	return (is_avl_helper(tree->left, min, tree->n) &&
			is_avl_helper(tree->right, tree->n, max));
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
