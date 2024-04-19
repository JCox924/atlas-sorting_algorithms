#include "sort.h"
#include "swap.c"

/*
 * bubble_sort - sorts array using the bubble sort algorithm
 *
 * @array: Array to be sorted
 *
 * @size: Size of array
 *
 * Description: sorts and array by placing largest ints and end of array
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	unsigned int i, j;

	if (!array)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
