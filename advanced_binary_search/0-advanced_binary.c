#include <stdio.h>
#include <stddef.h>
#include "search_algos.h"


/**
 * print_array - Print the array or sub-array
 *
 * @array: Pointer to the first element of the array
 * @start: index of the first element
 * @end: index of the last element
 */
void print_array(int *array, int start, int end)

{
	printf("Searching in array: ");
	for (int i = start; i <= end; i++)
	{
		printf("%d", array[i]);
		if (i != end)
			printf(", ");
	}
	printf("\n");
}


/**
 * search - Searches for a value in a sorted array of integers
 *
 * @array: Pointer to the first element of the array
 * @start: index of the first element
 * @end: index of the last element
 * @value: Value to search for
 * Return: index of the value or -1 if failed
 */
int search(int *array, int start, int end, int value)

{
	if (end >= start)
	{
		print_array(array, start, end);
		int half = start + (end - start) / 2;

		if (array[half] == value && array[half - 1] != value)
			return (half);

		if (array[half] >= value)
			return (search(array, start, half, value));

		return (search(array, half + 1, end, value));
	}
	return (-1);
}


/**
 * advanced_binary - Call the function search
 *
 * @array: Pointer to the first element of the array
 * @size: Number of elements in array
 * @value: Value to search for
 * Return: index of the value or -1 if failed
 */
int advanced_binary(int *array, size_t size, int value)

{
	if (array == NULL || size == 0)
		return (-1);
	if (size == 1)
		return (1);
	int start = 0, end = size - 1;

	return (search(array, start, end, value));
}
