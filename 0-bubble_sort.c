#include "sort.h"
void swap(int *a, int *b);

/**
 * bubble_sort - Sorts an array of integers in ascending order
 *
 * @array:An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Print the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, new_len, len;

	if (array == NULL || size < 2)
		return;

	len = size;
	while (len > 1)
	{
		for (i = 1; i <= len - 1; i++)
		{
			if (array[i - 1] > array[i])
			{
				swap(&array[i - 1], &array[i]);
				print_array(array, size);
			}
			new_len = i;
		}
		len = new_len;
	}
}

/**
 * swap - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
