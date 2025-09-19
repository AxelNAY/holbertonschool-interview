#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * merge_sort - Sorts an array of integers in ascending order
 *              using the Merge Sort algorithm.
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 *
 */

void merge_sort(int *array, size_t size)
{

	int *new_array = malloc(sizeof(int) * size);

	if (new_array == NULL)
		return;

	merge_sort_helper(array, size, new_array);

	free(new_array);
}

/**
 * merge_sort_helper - Helper function that recursively divides
 *                     and sorts the array.
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @new_array: Temporary array for merging
 *
 */
void merge_sort_helper(int *array, size_t size, int *new_array)
{
	int middle = size / 2;

	if (size < 2)
		return;

	merge_sort_helper(array, middle, new_array);
	merge_sort_helper(array + middle, size - middle, new_array);
	merge(array, size, new_array, middle);
}

/**
 * merge - Merges two sorted halves of an array into a single sorted array.
 *
 * @array: The array to be merged
 * @size: Number of elements in @array
 * @new_array: Temporary array for merging
 * @middle: The index that divides the two halves
 *
 */
void merge(int *array, size_t size, int *new_array, int middle)
{
	int left = 0, right = middle, i = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, middle);
	printf("[right]: ");
	print_array(array + middle, size - middle);

	while (left < middle && right < (int)size)
	{
		if (array[left] < array[right])
			new_array[i++] = array[left++];
		else
			new_array[i++] = array[right++];
	}

	while (left < middle)
		new_array[i++] = array[left++];

	while (right < (int)size)
		new_array[i++] = array[right++];

	for (i = 0; i < (int)size; i++)
		array[i] = new_array[i];

	printf("[Done]: ");
	print_array(array, size);
}
