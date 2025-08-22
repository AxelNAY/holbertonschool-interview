#include <stdlib.h>
#include <stdio.h>

#include "binary_trees.h"

/**
 * count_nodes - Count the total number of nodes in the heap
 * @root: pointer to the root node
 * Return: number of nodes
 */
int count_nodes(heap_t *root)
{
    if (!root)
        return (0);
    return (1 + count_nodes(root->left) + count_nodes(root->right));
}

/**
 * find_last_node - Find the last node in level order (rightmost of last level)
 * @root: pointer to the root node
 * @index: current index (1-based)
 * @total: total number of nodes
 * Return: pointer to the last node
 */
heap_t *find_last_node(heap_t *root, int index, int total)
{
    heap_t *left_result, *right_result;

    if (!root)
        return (NULL);
    
    if (index == total)
        return (root);
    
    left_result = find_last_node(root->left, 2 * index, total);
    if (left_result)
        return (left_result);
    
    right_result = find_last_node(root->right, 2 * index + 1, total);
    return (right_result);
}

/**
 * heapify_down - Restore heap property by moving node down
 * @node: pointer to the node to heapify
 */
void heapify_down(heap_t *node)
{
    heap_t *largest;
    int temp;

    if (!node)
        return;

    largest = node;

    if (node->left && node->left->n > largest->n)
        largest = node->left;

    if (node->right && node->right->n > largest->n)
        largest = node->right;

    if (largest != node)
    {
        temp = node->n;
        node->n = largest->n;
        largest->n = temp;
        heapify_down(largest);
    }
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

    total_nodes = count_nodes(*root);
    last_node = find_last_node(*root, 1, total_nodes);

    (*root)->n = last_node->n;

    if (last_node->parent)
    {
        if (last_node->parent->left == last_node)
            last_node->parent->left = NULL;
        else
            last_node->parent->right = NULL;
    }
    free(last_node);

    heapify_down(*root);

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
