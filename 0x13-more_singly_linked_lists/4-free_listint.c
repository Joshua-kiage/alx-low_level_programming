#include "lists.h"

/**
 * free_listint - Frees a linked list of integers.
 * @head: A pointer to the head node of the linked list.
 * Returns: Nothing
 */

void free_listint(listint_t *head)
{
	listint_t *next;

	while (head)
	{
		next = head->next;
		free(head);
		head = next;
	}
}
