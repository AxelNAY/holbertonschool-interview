#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/**
 * add_node_end - Add a new node to the end of a double circular linked list
 *
 * @list: list to modify
 * @str: string to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *newNode, *last;

	if (!str)
		return (NULL);

	newNode = malloc(sizeof(List));
	if (!newNode)
		return (NULL);

	newNode->str = str;

	if (!list)
	{
		newNode->next = newNode;
		newNode->prev = newNode;
		*list = newNode;
	}
	else
	{
		last = (*list)->prev;

		newNode->next = *list;
		newNode->prev = last;
		last->next = newNode;
		(*list)->prev = newNode;
	}

	return (newNode);
}


/**
 * add_node_begin - Add a new node to the beginning
 * of a double circular linked list
 * @list: list to modify
 * @str: string to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *newNode, *last;

	if (!str)
		return (NULL);

	newNode = malloc(sizeof(List));
	if (!newNode)
		return (NULL);

	newNode->str = str;

	if (*list == NULL)
	{
		newNode->next = newNode;
		newNode->prev = newNode;
		*list = newNode;
	}
	else
	{
		last = (*list)->prev;

		newNode->next = *list;
		newNode->prev = last;
		(*list)->prev = newNode;
		last->next = newNode;
		*list = newNode;
	}

	return (newNode);
}
