#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table
 * @size: The size of the array
 * Return: A pointer to the newly created hash table, or NULL if it fails
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht = NULL;
	unsigned long int i = 0;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}
	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}
/**
 * shash_table_set - Adds an element to the sorted hash table
 * @ht: The hash table
 * @key: The key of the element
 * @value: The value associated with the key
 * Return: 1 on success, 0 on failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index = 0;
	shash_node_t *new_node = NULL;
	shash_node_t *tmp = NULL;
	shash_node_t *prev = NULL;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = hash_djb2((const unsigned char *)key) % ht->size;
	tmp = ht->array[index];

	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = strdup(value);
			return (1);
		}
		tmp = tmp->next;
	}
	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
		return (0);

	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	if (ht->shead == NULL || strcmp(ht->shead->key, key) > 0)
	{
		new_node->snext = ht->shead;
		new_node->sprev = NULL;
		if (ht->shead != NULL)
			ht->shead->sprev = new_node;
		ht->shead = new_node;
	}
	else
	{
		tmp = ht->shead;
		while (tmp != NULL && strcmp(tmp->key, key) < 0)
		{
			prev = tmp;
			tmp = tmp->snext;
		}

		new_node->sprev = prev;
		new_node->snext = tmp;
		prev->snext = new_node;
		if (tmp != NULL)
			tmp->sprev = new_node;
	}
	if (new_node->snext == NULL)
		ht->stail = new_node;

	return (1);
}
/**
 * shash_table_get - Retrieves a value associated with a key
 *                   in the sorted hash table
 * @ht: The hash table
 * @key: The key to search for
 * Return: The value associated with the key, or NULL if key is not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index = 0;
	shash_node_t *tmp = NULL;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = hash_djb2((const unsigned char *)key) % ht->size;
	tmp = ht->array[index];

	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}
/**
 * shash_table_print - Prints the sorted hash table in the order
 *                     of the sorted linked list
 * @ht: The hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *tmp = NULL;
	int flag = 0;

	if (ht == NULL)
		return;

	tmp = ht->shead;
	printf("{");
	while (tmp != NULL)
	{
		if (flag == 0)
			flag = 1;
		else
			printf(", ");
		printf("'%s': '%s'", tmp->key, tmp->value);
		tmp = tmp->snext;
	}
	printf("}\n");
}
/**
 * shash_table_print_rev - Prints the sorted hash table in reverse order
 *                         of the sorted linked list
 * @ht: The hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *tmp = NULL;
	int flag = 0;

	if (ht == NULL)
		return;

	tmp = ht->stail;
	printf("{");
	while (tmp != NULL)
	{
		if (flag == 0)
			flag = 1;
		else
			printf(", ");
		printf("'%s': '%s'", tmp->key, tmp->value);
		tmp = tmp->sprev;
	}
	printf("}\n");
}
/**
 * shash_table_delete - Deletes a sorted hash table
 * @ht: The hash table to be deleted
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *tmp = NULL;
	shash_node_t *next = NULL;
	unsigned long int i = 0;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		tmp = ht->array[i];
		while (tmp != NULL)
		{
			next = tmp->next;
			free(tmp->key);
			free(tmp->value);
			free(tmp);
			tmp = next;
		}
	}
	free(ht->array);
	free(ht);
}
