#include <stdio.h>
#include <string.h>
#include "holberton.h"

/**
 * wildCardRec - Compares two strings allowing the wildcard character '*'
 *
 * @s1: first string
 * @s2: second string
 * @len_s1: lenght of the first string
 * @len_s2: lenght of the second string
 *
 * Return: 1 if the strings can be considered identical,
 * otherwise return 0
 */
int wildCardRec(char *s1, char *s2, int len_s1, int len_s2)
{
	if (len_s2 == 0)
		return (len_s1 == 0);

	if (s1[len_s1 - 1] == s2[len_s2 - 1])
		return (wildCardRec(s1, s2, len_s1 - 1, len_s2 - 1));

	if (s2[len_s2 - 1] == '*')
		return (wildCardRec(s1, s2, len_s1, len_s2 - 1) ||
			   wildCardRec(s1, s2, len_s1 - 1, len_s2));

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
	int len_s1 = strlen(s1);
	int len_s2 = strlen(s2);

	return (wildCardRec(s1, s2, len_s1, len_s2));
}
