#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 * using the Insertion Sort algorithm.
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current, *temp, *sorted = NULL;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

while (*list)
{
current = *list;
*list = (*list)->next;

if (sorted == NULL || current->n <= sorted->n)
{
current->next = sorted;
if (sorted)
sorted->prev = current;
current->prev = NULL;
sorted = current;
}
else
{
temp = sorted;
while (temp->next && temp->next->n < current->n)
temp = temp->next;

current->next = temp->next;
if (temp->next)
temp->next->prev = current;
temp->next = current;
current->prev = temp;
}
print_list(sorted);
}

*list = sorted;
}

