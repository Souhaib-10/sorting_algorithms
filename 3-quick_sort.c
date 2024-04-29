#include "sort.h"

/**
 * swap - Swaps two integers in an array.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - Partitions a subset of an array of integers using
 *             the Lomuto partition scheme.
 * @array: Pointer to the array of integers.
 * @size: Size of the array.
 * @low: The starting index of the subset to partition.
 * @high: The ending index of the subset to partition.
 *
 * Return: The final partition index.
 */
int partition(int *array, size_t size, int low, int high)
{
	int pivot, above, below;

	pivot = array[high];
	for (above = below = low; below < high; below++)
	{
		if (array[below] < pivot)
		{
			if (above < below)
			{
				swap(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > pivot)
	{
		swap(array + above, array + high);
		print_array(array, size);
	}

	return (above);
}

/**
 * quick_sort_recursive - Sorts an array of integers in ascending order
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 * @low: The starting index of the array partition to sort.
 * @high: The ending index of the array partition to sort.
 */
void quick_sort_recursive(int *array, size_t size, int low, int high)
{
	int part;

	if (high - low > 0)
	{
		part = partition(array, size, low, high);
		quick_sort_recursive(array, size, low, part - 1);
		quick_sort_recursive(array, size, part + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the quicksort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 *
 * Description: Sorts the array using the Lomuto partition scheme
 *              and prints the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, size, 0, size - 1);
}

