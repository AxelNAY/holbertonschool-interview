#include <stdlib.h>
#include <stdio.h>
#include "regex.h"


/**
 * regex_match - Checks whether a given pattern matches a given string
 *
 * @str: string to scan
 * @pattern: regular expression
 * Return: 1 on success or 0 on failure
 */
int regex_match(char const *str, char const *pattern)
{
	if (!str || !pattern)
		return (0);

	if (*pattern == '\0')
		return (*str == '\0');

	if (pattern[1] == '*')
	{
		if (regex_match(str, pattern + 2))
			return (1);

		if (*str != '\0' && (*str == *pattern || *pattern == '.'))
			return (regex_match(str + 1, pattern));

		return (0);
	}

	if (*str != '\0' && (*str == *pattern || *pattern == '.'))
		return (regex_match(str + 1, pattern + 1));

	return (0);
}
