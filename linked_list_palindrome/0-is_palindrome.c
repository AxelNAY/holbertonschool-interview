#include <stdio.h>
#include "lists.h"

listint_t *reverse_list(listint_t *head)
{
    listint_t *prev = NULL, *next = NULL;

    while (head)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

int is_palindrome(listint_t **head)
{
    listint_t *slow, *fast, *second_half, *first_half, *reversed;

    if (!head || !*head || !(*head)->next)
        return 1;

    slow = fast = *head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    second_half = reverse_list(slow);
    reversed = second_half;

    first_half = *head;
    while (second_half)
    {
        if (first_half->n != second_half->n)
        {
            reverse_list(reversed);
            return 0;
        }
        first_half = first_half->next;
        second_half = second_half->next;
    }

    reverse_list(reversed);

    return 1;
}
