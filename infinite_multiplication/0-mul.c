#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

/**
 * is_number - check if a number is in base 10.
 * @num: number in string.
 * Return: 1 on success or 0 on fail.
 */
int is_number(const char *num)
{
	int i = 0;

	if (num == NULL || strlen(num) == 0 || num[0] == '-')
		return (0);

	for (; num[i] != '\0'; i++)
		if (!isdigit(num[i]))
			return (0);

	return (1);
}

/**
 * print_result - Print the multiplication result
 * @result: Array containing the result digits
 * @len: Length of the result array
 */
void print_result(int *result, int len)
{
	int start = 0, i;

	while (start < len - 1 && result[start] == 0)
		start++;

	for (i = start; i < len; i++)
		printf("%d", result[i]);
	printf("\n");
}

/**
 * multiply_big_numbers - Multiply two large numbers stored as strings
 * @num1: First number as string
 * @num2: Second number as string
 */
void multiply_big_numbers(const char *num1, const char *num2)
{
	int len1 = strlen(num1), len2 = strlen(num2);
	int result_len = len1 + len2, i, j;
	int *result = calloc(result_len, sizeof(int));

	if (!result)
	{
		printf("Error\n");
		exit(98);
	}
	if (strcmp(num1, "0") == 0 || strcmp(num2, "0") == 0)
	{
		printf("0\n");
		free(result);
		return;
	}

	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			int product = (num1[i] - '0') * (num2[j] - '0');
			int pos = i + j + 1;
			int sum = product + result[pos];

			result[pos] = sum % 10;
			result[pos - 1] += sum / 10;
		}
	}

	print_result(result, result_len);
	free(result);
}

/**
 * infinite - Multiply 2 number enter in line command
 * @ac: Arguments counter
 * @av: Arguments vector
 */
void infinite(int ac, char **av)
{
	if (ac != 3)
	{
		printf("Error\n");
		exit(98);
	}
	if (is_number(av[1]) == 0 || is_number(av[2]) == 0)
	{
		printf("Error\n");
		exit(98);
	}

	multiply_big_numbers(av[1], av[2]);
}

/**
 * main - check the code for Holberton School students.
 * @ac: Arguments counter
 * @av: Arguments vector
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	infinite(ac, av);
	return (0);
}
