#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * find_insert_position - finds the next available position in the heap
 * @root: pointer to the root node of the Heap
 *
 * Return: pointer to the parent node where to insert
 */
heap_t *find_insert_position(heap_t *root)
{
heap_t *current, *temp;
int nodes_left, nodes_right;

current = root;
while (1)
{
if (current->left == NULL || current->right == NULL)
return (current);

temp = current->left;
nodes_left = 1;
while (temp->left != NULL)
{
nodes_left *= 2;
temp = temp->left;
}

temp = current->right;
nodes_right = 1;
while (temp->left != NULL)
{
nodes_right *= 2;
temp = temp->left;
}

if (nodes_left <= nodes_right)
current = current->left;
else
current = current->right;
}
}

/**
 * bubble_up - restores the max heap property by bubbling up a node
 * @node: pointer to the node to bubble up
 * @root: double pointer to the root of the heap
 *
 * Return: pointer to the final position of the node
 */
heap_t *bubble_up(heap_t *node, heap_t **root)
{
int temp;

while (node->parent != NULL && node->n > node->parent->n)
{
temp = node->n;
node->n = node->parent->n;
node->parent->n = temp;
node = node->parent;
}

if (node->parent == NULL)
*root = node;

return (node);
}

/**
 * heap_insert - inserts a value into a Max Binary Heap
 *
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 *
 * Return: A pointer to the new node if Success or NULL if Fail
 */
heap_t *heap_insert(heap_t **root, int value)
{
heap_t *new_node, *parent;

if (root == NULL)
return (NULL);

new_node = binary_tree_node(NULL, value);
if (new_node == NULL)
return (NULL);

if (*root == NULL)
{
*root = new_node;
return (new_node);
}

parent = find_insert_position(*root);

if (parent->left == NULL)
parent->left = new_node;
else
parent->right = new_node;
new_node->parent = parent;

return (bubble_up(new_node, root));
}
