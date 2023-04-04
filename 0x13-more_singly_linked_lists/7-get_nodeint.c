#include "lists.h"

/**
 * get_nodeint_at_index - Returns the nth node of a listint_t linked list.
 * @head: Pointer to the head node of the linked list.
 * @index: The index of the node to retrieve (starting at 0).
 * Return: If successful, a pointer to the requested node. Otherwise, NULL.
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *current = head;
	unsigned int i;

	for (i = 0; current != NULL; i++)
	{
		if (i == index)
		{
			return (current);
		}
		current = current->next;
	}

	return (NULL);
}
