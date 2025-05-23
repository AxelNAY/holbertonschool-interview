#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * count_nodes_before - counts the number of nodes before a given position
 * @list: start of the list
 * @target: target node
 * @current: current node in traversal
 * @count: current counter
 *
 * Return: number of nodes before the target node
 */
int count_nodes_before(listint_t *list, listint_t *target,
		       listint_t *current, int count)
{
	if (current == target)
		return (count);
	if (current == NULL)
		return (count);

	return (count_nodes_before(list, target, current->next, count + 1));
}

/**
 * check_value_in_range - checks if a value exists in a range of nodes
 * @list: start of the list
 * @value: value to search for
 * @range: number of nodes to check
 * @current: current node
 *
 * Return: 1 if value is found in range, 0 otherwise
 */
int check_value_in_range(listint_t *list, int value, int range,
			 listint_t *current)
{
	if (range <= 0 || current == NULL)
		return (0);

	if (current->n == value)
		return (1);

	return (check_value_in_range(list, value, range - 1, current->next));
}

/**
 * check_cycle_recursive - recursive function to check for cycles
 * @list: start of the list
 * @current: current node to check
 * @position: current position in the list
 *
 * Return: 1 if cycle is detected, 0 otherwise
 */
int check_cycle_recursive(listint_t *list, listint_t *current, int position)
{
	if (current == NULL)
		return (0);

	/* Check if current value exists in previous nodes */
	if (check_value_in_range(list, current->n, position, list))
		return (1);

	/* Continue recursively with next node */
	return (check_cycle_recursive(list, current->next, position + 1));
}

/**
 * check_cycle - check if list is a cycle
 * @list: list to check
 *
 * Return: 1 if Success of 0 if Fail
 */
int check_cycle(listint_t *list)
{
	if (list == NULL)
		return (0);

	return (check_cycle_recursive(list, list, 0));
}
