#include "sort.h"

void swap_node(listint_t **h, listint_t **node1, listint_t **node2);
/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 * ascending order.
 *@list: A doubly linked list of integers to be sorted
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current)
	{
		temp = current->next;
		prev = current->prev;

		while (prev && current->n < prev->n)
		{
			swap_node(list, &prev, &current);
			print_list(*list);
			prev = current->prev;
		}
		current = temp;
	}
}

/**
 * swap_node - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @node1: A pointer to the first node to swap.
 * @node2: A pointer to the second node to swap.
 */
void swap_node(listint_t **h, listint_t **node1, listint_t **node2)
{
	listint_t *n1, *n2;

	n1 = *node1;
	n2 = *node2;

	if (n1->prev != NULL)
		n1->prev->next = n2;
	else
		*h = n2;
	if (n2->next != NULL)
		n2->next->prev = n1;

	n1->next = n2->next;
	n2->prev = n1->prev;

	n2->next = n1;
	n1->prev = n2;
}
