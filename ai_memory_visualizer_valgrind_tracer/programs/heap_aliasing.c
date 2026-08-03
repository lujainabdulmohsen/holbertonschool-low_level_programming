#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *first;
	int *second;

	first = malloc(sizeof(int));
	if (first == NULL)
		return (1);

	*first = 25;
	second = first;
	printf("%d %d\n", *first, *second);

	*second = 50;
	printf("%d %d\n", *first, *second);

	free(first);
	first = NULL;
	second = NULL;

	return (0);
}
