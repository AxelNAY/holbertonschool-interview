#include <stdlib.h>
#include <stdio.h>
#include "palindrome.h"


/**
 * is_palindrome - Check if a number is palindrome
 *
 * @n: Number to check
 *
 * Return: 1 if success or 0 if fail
 */
int is_palindrome(unsigned long n)
{
    int tab[20];
    int min = 0, max = 0;
    unsigned long temp = n;

    while (temp != 0)
    {
        temp /= 10;
        max++;
    }

    if (max == 1)
    {
        return (1);
    }

    max--;

    for (int i = max; i >= 0; i--)
    {
        tab[i] = n % 10;
        n /= 10;
    }

    while (min < max)
    {
        if (tab[min] != tab[max])
        {
            return (0);
        }
        min++;
        max--;
    }

    return (1);
}
