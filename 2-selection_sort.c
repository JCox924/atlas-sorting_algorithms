#include "sort.h"
#include "swap.c"

/**
 * selection_sort - sorts array using selection sort
 *
 * @array: pointer to array to be sorted
 *
 * @size: Size of array given
 *
 * Description: function that sorts an array using the selection
 * sort algotrithm
 *
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	unsigned int i, j, min_idx;

	if (!array)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min_idx])
				min_idx = j;

		if (i != min_idx)
		{
			swap(&array[min_idx], &array[i]);
			print_array(array, size);
		}
	}
}

