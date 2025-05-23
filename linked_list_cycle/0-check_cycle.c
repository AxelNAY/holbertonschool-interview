#include <stdio.h>
#include <stdlib.h>
#include "lists.h"


/**
* check_cycle - check if list is a cycle
* @list: list to check
*
* Return: 1 if Success of 0 if Fail
*/
int check_cycle(listint_t *list)
{
	listint_t *temp, *node_storage;
	int i = 0, j;

	temp = list;

	while (list != NULL)
	{
		node_storage = temp;
		j = 0;
		while (j < i)
		{
			if (list->n == node_storage->n)
			{
				return (1);
			}
			node_storage = node_storage->next;
			j++;
		}
		list = list->next;
		i++;
	}

	return (0);
}
