#include <stdlib.h>
#include <stdio.h>
#include "sort.h"


/**
 * getMax - Get the maximum
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 *
 * Return: the maximum
 */
int getMax(int *array, size_t size)
{
	int mx = array[0];

	for (size_t i = 1; i < size; i++)
		if (array[i] > mx)
			mx = array[i];
	return (mx);
}


/**
 * countSort - Counting sort of array
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 * @exp: 10^i where i is the current
 */
void countSort(int *array, size_t size, int exp)
{
	int output[size];
	int count[10] = {0};

	for (size_t i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (int i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (size_t i = 0; i < size; i++)
		array[i] = output[i];
	print_array(array, size);
}


/**
 * radix_sort - Sorts an array of integers in ascending order
 * using the Radix sort algorithm.
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void radix_sort(int *array, size_t size)
{
	if (size < 2)
	{
		return ();
	}

	int m = getMax(array, size);

	for (size_t exp = 1; m / exp > 0; exp *= 10)
		countSort(array, size, exp);
}
