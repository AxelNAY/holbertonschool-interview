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
	listint_t *current = list;
	listint_t *temp = list;

	while (temp != NULL && temp->next != NULL)
	{
		current = current->next;
		temp = temp->next->next;

		if (current == temp)
		{
			return (1);
		}
	}

	return (0);
}
