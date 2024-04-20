#include "sort.h"
#include "swap.c"

/**
 * quick_sort - Function that sorts an array based on
 * quick sort algorithm
 *
 * @array: pointer to array to be sorted
 *
 * @size: Size of array
 *
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	size_t pivot;

	if (!array || size < 2)
		return;

	print_sort(array, size, 1);

	pivot = partition(array, size);

	quick_sort(array, pivot);
	quick_sort(array + pivot, size - pivot);
}

/*
 * partition - sets the pivot for quick_sort
 *
 * @array: sub-array origin
 *
 * @size: Size of array
 *
 * Return: (i + 1)
 */

size_t partition(int array[], size_t size)
{
	int pivot;
	size_t i = -1;
	size_t j;

	if (!array || size < 2)
		return (0);

	pivot = array[size - 1];

	for (j = 0; j < size - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_sort(array, size, 0);
			}
		}
	}
	if (i + 1 != size - 1)
	{
		swap(&array[i + 1], &array[size - 1]);
		print_sort(array, size, 0);
	}
	return (i + 1);
}

/*
 * print_sort - prints sorted array
 *
 * @array: array to be printed
 *
 * @size: Size of array
 *
 * @init: initialize array
 *
 * Return: void
 */

void print_sort(int array[], size_t size, int init)
{
	static int *p = (void *)0;
	static size_t s;

	if (!p && init)
	{
		p = array;
		s = size;
	}
	if (!init)
		print_array(p, s);
}
