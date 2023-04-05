#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list and sets head to NULL
 * @h: Pointer to a pointer to the head of the list
 * Return: The size of the list that was freed
 */

size_t free_listint_safe(listint_t **h)
{
	size_t size = 0;
	int diff;

	listint_t *current;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		diff = *h - (*h)->next;
		if (diff > 0)
		{
			current = (*h)->next;
			free(*h);
			*h = current;
			size++;
		}
		else
		{
			free(*h);
			*h = NULL;
			size++;
			break;
		}
	}
	*h = NULL;
	return (size);
}
