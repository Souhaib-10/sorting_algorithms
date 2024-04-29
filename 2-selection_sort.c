#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 *
 * Description: Swaps the values of two integers in an array.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 *
 * Description: This function implements the selection sort algorithm
 *              and prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *small;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		small = array + i;

		for (j = i + 1; j < size; j++)
			small = (array[j] < *small) ? (array + j) : small;

		if ((array + i) != small)
		{
			swap_ints(array + i, small);
			print_array(array, size);
		}
	}
}
