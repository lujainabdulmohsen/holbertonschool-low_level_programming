#include "hash_tables.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * shash_table_create - creates a sorted hash table
 * @size: size of the array
 *
 * Return: pointer to the new hash table, or NULL
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->array = calloc(size, sizeof(shash_node_t *));
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	ht->size = size;
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * create_shash_node - creates a sorted hash node
 * @key: key
 * @value: value
 *
 * Return: pointer to the new node, or NULL
 */
shash_node_t *create_shash_node(const char *key, const char *value)
{
	shash_node_t *node;

	node = malloc(sizeof(shash_node_t));
	if (node == NULL)
		return (NULL);

	node->key = strdup(key);
	node->value = strdup(value);
	if (node->key == NULL || node->value == NULL)
	{
		free(node->key);
		free(node->value);
		free(node);
		return (NULL);
	}

	node->next = NULL;
	node->sprev = NULL;
	node->snext = NULL;

	return (node);
}

/**
 * insert_sorted_node - inserts a node in sorted order
 * @ht: sorted hash table
 * @node: node to insert
 */
void insert_sorted_node(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *current;

	if (ht->shead == NULL)
	{
		ht->shead = node;
		ht->stail = node;
		return;
	}

	current = ht->shead;
	while (current != NULL && strcmp(current->key, node->key) < 0)
		current = current->snext;

	if (current == ht->shead)
	{
		node->snext = ht->shead;
		ht->shead->sprev = node;
		ht->shead = node;
	}
	else if (current == NULL)
	{
		node->sprev = ht->stail;
		ht->stail->snext = node;
		ht->stail = node;
	}
	else
	{
		node->sprev = current->sprev;
		node->snext = current;
		current->sprev->snext = node;
		current->sprev = node;
	}
}

/**
 * shash_table_set - adds an element to a sorted hash table
 * @ht: sorted hash table
 * @key: key
 * @value: value
 *
 * Return: 1 on success, 0 on failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *node;
	char *new_value;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	for (node = ht->array[index]; node != NULL; node = node->next)
	{
		if (strcmp(node->key, key) == 0)
		{
			new_value = strdup(value);
			if (new_value == NULL)
				return (0);
			free(node->value);
			node->value = new_value;
			return (1);
		}
	}

	node = create_shash_node(key, value);
	if (node == NULL)
		return (0);

	node->next = ht->array[index];
	ht->array[index] = node;
	insert_sorted_node(ht, node);

	return (1);
}

/**
 * shash_table_get - retrieves a value associated with a key
 * @ht: sorted hash table
 * @key: key
 *
 * Return: value associated with key, or NULL
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *node;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];

	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}

	return (NULL);
}

/**
 * shash_table_print - prints a sorted hash table
 * @ht: sorted hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;
	int first = 1;

	if (ht == NULL)
		return;

	printf("{");
	for (node = ht->shead; node != NULL; node = node->snext)
	{
		if (!first)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		first = 0;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints a sorted hash table in reverse
 * @ht: sorted hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;
	int first = 1;

	if (ht == NULL)
		return;

	printf("{");
	for (node = ht->stail; node != NULL; node = node->sprev)
	{
		if (!first)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		first = 0;
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a sorted hash table
 * @ht: sorted hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node;
	shash_node_t *next;

	if (ht == NULL)
		return;

	node = ht->shead;
	while (node != NULL)
	{
		next = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = next;
	}

	free(ht->array);
	free(ht);
}
