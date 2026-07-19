#include "main.h"
#include <stdlib.h>

/**
 * _realloc - reallocates a memory block
 * @ptr: pointer to previously allocated memory
 * @old_size: old size in bytes
 * @new_size: new size in bytes
 *
 * Return: pointer to the new memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr;
	char *old_ptr;
	unsigned int i, size;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	old_ptr = ptr;
	size = old_size < new_size ? old_size : new_size;

	for (i = 0; i < size; i++)
		new_ptr[i] = old_ptr[i];

	free(ptr);

	return (new_ptr);
}
