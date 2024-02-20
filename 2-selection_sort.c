#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * selection_sort - Sorts an array of integers in ascending order
 * @array: The array to be sorted
 * @size: The array size
 */
void selection_sort(int *array, size_t size)
{
	size_t i,j, jMin;



	for (i = 0; i < size - 1; i++)
	{
		jMin = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[jMin])
			{
				jMin = j;
				continue;
			}
		}

		if (jMin != i)
		{
			swap_ints(&array[i], &array[jMin]);
			print_array(array, size);
		}
	}
}
