#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *number;

	number = malloc(sizeof(int));
	if (number == NULL)
		return (1);

	if (*number > 0)
		printf("positive\n");

	free(number);

	return (0);
}
