#include "lists.h"

/**
 * pop_listint - Deletes the head node of a listint_t linked list and returns
 *               the head node's data (n).
 * @head: Double pointer to the head node of the linked list.
 * Return:  The head node’s data (n), if the linked list is empty return 0
 */

int pop_listint(listint_t **head)
{
	int data;
	listint_t *next;

	if (*head == NULL)
		return (0);

	data = (*head)->n;
	next = *head;

	*head = (*head)->next;
	free(next);

	return (data);
}
