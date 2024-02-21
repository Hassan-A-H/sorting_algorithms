#include "sort.h"

void swap_ints(int *a, int *b);
void lomuto_sort(int *array, size_t size, int lo, int hi);
size_t partition(int *array, size_t size, int lo, int hi);
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto_sort(array, size, 0, size - 1);
}

void lomuto_sort(int *array, size_t size, int lo, int hi)
{
	int p;

	if (lo >= hi || lo < 0)
		return;

	p = partition(array, size, lo, hi);

	lomuto_sort(array, size, lo, p - 1);
	lomuto_sort(array, size, p + 1, hi);
}
size_t partition(int *array, size_t size, int lo, int hi)
{
	int i, j, pivot;

	pivot = hi;
	i = lo - 1;
	for (j = lo; j < hi; j++)
	{
		if (array[j] <= array[pivot])
		{
			i += 1;
			swap_ints(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	i = i + 1;
	swap_ints(&array[pivot], &array[i]);
	return (i);
}

void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
