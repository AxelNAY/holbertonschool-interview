#include <stdio.h>
#include <stdlib.h>
#include "lists.h"


int is_palindrome(listint_t **head) {
    int i = 0, j, size = 0;
    listint_t *copy, *first, *second;
    copy = *head;

    if (!head || !*head || !(*head)->next)
        return (1);

    while (copy != NULL)
    {
        copy = copy->next;
        size++;
    }

    while (i != size / 2) {
        first = second = *head;
        for (j = 0; j < i; j++)
        {
            first = first->next;
        }
        for (j = 0; j < size - (i + 1); j++)
        {
            second = second->next;
        }
        if (first->n != second->n)
        {
            return (0);
        }
        else
        {
            i++;
        }
    }

    return (1);
}
