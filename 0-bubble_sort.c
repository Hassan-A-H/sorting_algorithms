#include "sort.h"

/**
 * swap_nodes - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_nodes(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	int bubbly = 0;

	if (array == NULL || size < 2)
		return;

	while (bubbly == 0)
	{
		bubbly = 1;
		for (i = 1; i < len; i++)
		{
			if (array[i - 1] > array[i])
			{
				swap_nodes(&array[i - 1], &array[i]);
				print_array(array, size);
				bubbly = 0;
			}
		}
		len--;
	}
}
