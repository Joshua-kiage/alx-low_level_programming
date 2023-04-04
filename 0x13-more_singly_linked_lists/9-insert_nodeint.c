#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position
 * @head: Pointer to a pointer to the head of the linked list
 * @idx: Index where the new node should be added (starting from 0)
 * @n: Value to be inserted in the new node
 * Return: Address of the new node, or NULL if it failed
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *prev = *head;
	unsigned int i;
	listint_t *new_node = malloc(sizeof(listint_t));

	if (head == NULL)
		return (NULL);

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}
	for (i = 0; i < idx - 1; i++)
	{
		if (prev == NULL)
		{
			free(new_node);
			return (NULL);
		}
		prev = prev->next;
	}

	if (prev == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->next = prev->next;
	prev->next = new_node;

	return (new_node);
}
