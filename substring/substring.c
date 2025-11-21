#include <stdlib.h>
#include <string.h>
#include "substring.h"


/**
 * match_all - Checks if all given words appear consecutively starting
 * from a position in the string
 *
 * @s: String to scan
 * @words: Array of words all substrings must be a concatenation arrangement of
 * @nb_words: Number of elements in the array words
 * @wlen: Length of each word
 *
 * Return: 1 if all words are found exactly once in any order,
 * 0 otherwise.
 */
static int match_all(const char *s, const char **words, int nb_words, int wlen)
{
	int used[1000] = {0};
	int i, j;
	const char *seg;

	for (i = 0; i < nb_words; i++)
	{
		seg = s + i * wlen;
		for (j = 0; j < nb_words; j++)
		{
			if (!used[j] && strncmp(seg, words[j], wlen) == 0)
			{
				used[j] = 1;
				break;
			}
		}

		if (j == nb_words)
		{
			return (0);
		}
	}
	return (1);
}


/**
 * push_index - Inserts a found index into the result array
 * @arr: Array of indices where matches are stored
 * @n: Address at which to store the number of elements in the returned array
 * @idx: Index to insert
 */
static void push_index(int *arr, int *n, int idx)
{
	arr[*n] = idx;
	(*n)++;
}


/**
 * find_substring - Finds all the possible substrings containing
 * a list of words, within a given string
 *
 * @s: String to scan
 * @words: Array of words all substrings must be a concatenation arrangement of
 * @nb_words: Number of elements in the array words
 * @n: Address at which to store the number of elements in the returned array
 *
 * Return: An allocated array, storing each index in s,
 * at which a substring was found or NULL on failure
 */
int *find_substring(const char *s, const char **words, int nb_words, int *n)
{
	int *res, i, wlen, total, len;

	*n = 0;
	if (!s || !words || nb_words < 1)
	{
		return (NULL);
	}

	wlen = strlen(words[0]);
	len = strlen(s);
	total = wlen * nb_words;

	res = malloc(sizeof(int) * len);
	if (!res)
	{
		return (NULL);
	}

	for (i = 0; i <= len - total; i++)
	{
		if (match_all(s + i, words, nb_words, wlen))
			push_index(res, n, i);
	}

	if (*n == 0)
	{
		free(res);
		return (NULL);
	}
	return (res);
}
