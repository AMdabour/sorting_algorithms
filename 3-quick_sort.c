#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @start: The starting index of the subset to order.
 * @end: The ending index of the subset to order.
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int start, int end)
{
	int pivot = array[end];
	int i = start - 1;
	int j;

	for (j = start; j < end; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap_ints(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	if (array[i + 1] > pivot)
	{
		swap_ints(&array[i + 1], &array[end]);
		print_array(array, size);
	}

	return (i + 1);
}


/**
 * lomuto_sort - sorts an array of integers using quick sort algorithm
 * @array: an array of integers
 * @size: the size of the array
 */
void lomuto_sort(int *array, size_t size, int start, int end)
{
	int pivot;

	if (end <= start)
		return;

	pivot = lomuto_partition(array, size, start, end);
	lomuto_sort(array, size, start, pivot - 1);
	lomuto_sort(array, size, pivot + 1, end);
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
