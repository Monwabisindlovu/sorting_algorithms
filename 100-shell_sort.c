#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using
 * Shell sort with Knuth sequence
 * @array: The array to be sorted
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
size_t gap = 1, i, j;
int temp;

while (gap < size)
{
gap = gap * 3 + 1;
}
gap = (gap - 1) / 3;

while (gap > 0)
{
for (i = gap; i < size; i++)
{
temp = array[i];
j = i;
            
while (j >= gap && array[j - gap] > temp)
{
array[j] = array[j - gap];
j -= gap;
}
array[j] = temp;
}
print_array(array, size);
gap = (gap - 1) / 3;
}
}

