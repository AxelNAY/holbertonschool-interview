#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * create_node - creates a new node
 * @str: string to copy
 * Return: new_node
 *
 */

List *create_node(char *str)
{
	List *new_node = (List *)malloc(sizeof(List));

	if (!new_node)
		return (NULL);

	char *dup_str = strdup(str);

	if (!dup_str)
		return (NULL);

	new_node->str = dup_str;
	new_node->prev = new_node->next = NULL;

	return (new_node);
}

/**
 * add_node_end - adds a new node at the end of the list
 * @list: head of the list
 * @str: string to insert
 * Return: address of new node or NULL in case of failure
 */

List *add_node_end(List **list, char *str)
{
	List *new_node = create_node(str);
	List *head, *last = NULL;

	if (!new_node || !list)
		return (NULL);
	head = *list;

	if (!head)
	{
		new_node->next = new_node->prev = new_node;
		*list = new_node;
	} else
	{
		last = head->prev;
		new_node->next = head;
		last->next = new_node;
		new_node->prev = last;
		head->prev = new_node;

	}
	return (new_node);
}

/**
 * add_node_begin - adds a new node at the beginning of the list
 * @list: head of the list
 * @str: string to insert
 * Return: address of new node or NULL in case of failure
 */

List *add_node_begin(List **list, char *str)
{
	List *new_node = NULL;

	new_node = add_node_end(list, str);
	if (!new_node)
		return (NULL);

	*list = new_node;

	return (new_node);
}
