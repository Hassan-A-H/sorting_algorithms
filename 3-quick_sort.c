#include "sort.h"

void swap_ints(int *a, int *b);
void lomuto_sort(int *array, size_t size, int lo, int hi);
size_t partition(int *array, size_t size, int lo, int hi);
/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto_sort(array, size, 0, size - 1);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @lo: The starting index of the array partition to order.
 * @hi: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int lo, int hi)
{
	int p;

	if (lo >= hi || lo < 0)
		return;

	p = partition(array, size, lo, hi);

	lomuto_sort(array, size, lo, p - 1);
	lomuto_sort(array, size, p + 1, hi);
}
/**
 * partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @lo: The starting index of the subset to order.
 * @hi: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
size_t partition(int *array, size_t size, int lo, int hi)
{
	int i, j, pivot;

	pivot = hi;
	for (j = i = lo; j < hi; j++)
	{
		if (array[j] <= array[pivot])
		{
			swap_ints(&array[i], &array[j]);
			i++;
			print_array(array, size);
		}
	}
	swap_ints(&array[pivot], &array[i]);
	return (i);
}

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	if (*a != *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
}
