#include "sort.h"

/**
 * bubble_sort - a function to sort an array of integers in ascending
 *		order using bubble sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 * Return: no thing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, tmp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
