#include "sort.h"
#include <stdio.h>

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

recursive_quick_sort(array, 0, size - 1, size);
}

/**
 * recursive_quick_sort - Recursive function for Quick Sort.
 * @array: The array to be sorted.
 * @low: The lower index of the partition.
 * @high: The higher index of the partition.
 * @size: The size of the array.
 */
void recursive_quick_sort(int *array, int low, int high, size_t size)
{
if (low < high)
{
int pi = lomuto_partition(array, low, high, size);

recursive_quick_sort(array, low, pi - 1, size);
recursive_quick_sort(array, pi + 1, high, size);
}
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick Sort.
 * @array: The array to be partitioned.
 * @low: The lower index of the partition.
 * @high: The higher index of the partition.
 * @size: The size of the array.
 * Return: The pivot index.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = (low - 1);
int j, tmp;

for (j = low; j <= high - 1; j++)
{
if (array[j] < pivot)
{
i++;
tmp = array[i];
array[i] = array[j];
array[j] = tmp;
if (i != j)
print_array(array, size);
}
}
tmp = array[i + 1];
array[i + 1] = array[high];
array[high] = tmp;
if (i + 1 != high)
print_array(array, size);
return (i + 1);
}

