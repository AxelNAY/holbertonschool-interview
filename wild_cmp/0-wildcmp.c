#include <stdio.h>
#include <string.h>
#include "holberton.h"


int voys2(char *s2)
{
    char *star = "*";
    if (*s2 == *star)
    {
        s2++;
        voys2(s2);
    }
    if (*s2 == '\0')
    {
        return (0);
    }
    printf("s2: %d\n", *s2);
    return (1);
}


int voys1(char *s1, char *s2)
{
    if (*s1 == '\0')
    {
        return (0);
    }
    if (*s1 != *s2)
    {
        s1++;
        voys1(s1, s2);
    }
    printf("s1: %d\n", *s1);
    return (1);
}


int compar(char *s1, char *s2)
{
    char *star = "*";

    if (*s2 == *star)
    {
        if (voys2(s2) == 0)
        {
            return (1);
        }
        if (voys1(s1, s2) == 0)
        {
            return (0);
        }
    }
    if (*s1 != *s2)
    {
        return (0);
    }
    s1++;
    s2++;
    if (*s1 == '\0' && *s2 == '\0')
        return (1);
    compar(s1, s2);
    return (0);
}


/**
 * wildcmp - compares two strings
 *
 * @s1: first string
 * @s2: second string
 *
 * Return: 1 if the strings can be considered identical,
 * otherwise return 0
 */
int wildcmp(char *s1, char *s2)
{
    if (compar(s1, s2) == 1)
        return (1);
    return (0);
}
