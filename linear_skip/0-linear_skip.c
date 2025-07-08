#include <stdio.h>
#include <stdlib.h>

#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 *
 * @list: Pointer to the head of the skip list to search in
 * @value: Value to search for
 *
 * Return: Pointer on the first node where value is located or NULL if value is not present in list or if head is NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    int verify = 0;
    size_t  index_min, index_max;
    skiplist_t *node, *res;

    if (value == 0)
    {
        return NULL;
    }
    for (node = list; node; node = node->express)
	{
		printf("Value checked at index[%lu] = [%d]\n", node->index, node->n);
        if (node->n >= value)
        {
            index_max = node->index;
            printf("Value found between indexes [%ld] and [%ld]\n", index_min, index_max);
            break;
        }
        else
        {
            index_min = node->index;
        }
	}
    while (node)
	{
        if (node->n == value)
        {
            verify = 1;
            res = node->index;
        }
        if (node->index >= index_min && node->index < index_max)
        {
            printf("Value checked at index[%lu] = [%d]\n", node->index, node->n);
        }
	}
    if (verify == 0)
    {
        return NULL;
    }
    return res;
}
