#include "sort.h"

/**
 * swap_nodes - swap the nodes
 * @head: a pointer to the head of the linked list
 * @node1: A pointer to the first node to swap
 * @node2 : A pointer to the second node to swap
 */
void swap_nodes(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
	{
		node2->next->prev = *node1;
	}
	node2->next = *node1;
	node2->prev = (*node1)->prev;
	if ((*node1)->prev != NULL)
	{
		(*node1)->prev->next = node2;
	}
	else
	{
		*head = node2;
	}
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - orts a doubly linked list of integers
 *		in ascending order using the Insertion sort algorithm.
 * @list: the linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *var1, *var2, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (var1 = (*list)->next; var1 != NULL; var1 = tmp)
	{
		tmp = var1->next;
		var2 = var1->prev;

		while (var2 != NULL && var2->n > var1->n)
		{
			swap_nodes(list, &var2, var1);
			print_list((const listint_t *)*list);
		}
	}
}
