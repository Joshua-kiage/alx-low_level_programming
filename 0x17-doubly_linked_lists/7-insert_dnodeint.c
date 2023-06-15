#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * insert_dnodeint_at_index - Inserts a new node at a given position
 *                            in a doubly linked list.
 * @h: Double pointer to the head of the list.
 * @idx: Index of the list where the new node should be added.
 *       Index starts at 0.
 * @n: Data to be stored in the new node.
 *
 * Return: Address of the new node, or NULL if it failed.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *temp, *node;
	unsigned int i = 0;

	if (h == NULL)
		return (NULL);

	node = malloc(sizeof(dlistint_t));
	if (node == NULL)
		return (NULL);
	node->n = n;
	node->prev = NULL;
	node->next = NULL;

	if (idx == 0 || *h == NULL)
	{
		node->next = *h;
		if (*h != NULL)
			(*h)->prev = node;
		*h = node;
	}
	else
	{
		temp = *h;
		while (temp != NULL && i < idx - 1)
		{
			temp = temp->next;
			i++;
		}
		if (temp == NULL)
		{
			free(node);
			return (NULL);
		}
		node->prev = temp;
		node->next = temp->next;

		if (temp->next != NULL)
			temp->next->prev = node;
		temp->next = node;
	}
	return (node);
}
