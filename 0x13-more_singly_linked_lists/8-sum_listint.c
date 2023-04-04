#include "lists.h"

/**
 * sum_listint - Returns the sum of all the data in a listint_t linked list.
 * @head: A pointer to the head of the linked list.
 *
 * Return: The sum of all the data in the linked list. If the list is empty,
 *         return 0.
 */

int sum_listint(listint_t *head)
{
	int sum = 0;

	listint_t *temp = head;

	while (temp != NULL)
	{
		sum += temp->n;
		temp = temp->next;
	}

	return (sum);
}
