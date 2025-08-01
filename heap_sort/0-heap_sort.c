#include "sort.h"

/**
 * heapify - To heapify a subtree rooted with node i which is an
 * index in arr[]
 *
 * @arr: A pointer to the first element of the array to be sorted
 * @size: The number of element in the array
 * @n: The size of the array part
 * @i: The indice of the node
 */
void heapify(int arr[], size_t size, int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest])
	{
		largest = left;
	}

	if (right < n && arr[right] > arr[largest])
	{
		largest = right;
	}

	if (largest != i)
	{
		int temp = arr[i];

		arr[i] = arr[largest];
		arr[largest] = temp;

		print_array(arr, size);
		heapify(arr, size, n, largest);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using
 * the Heap sort algorithm
 *
 * @array: A pointer to the first element of the array to be sorted
 * @size: The number of element in the array
 */
void heap_sort(int *array, size_t size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		heapify(array, size, size, i);
	}

	for (int i = size - 1; i > 0; i--)
	{
		int temp = array[0];

		array[0] = array[i];
		array[i] = temp;

		heapify(array, size, i, 0);
		print_array(array, size);
	}
}