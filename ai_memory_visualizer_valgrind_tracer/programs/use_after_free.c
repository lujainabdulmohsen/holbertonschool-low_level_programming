#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *number;

	number = malloc(sizeof(int));
	if (number == NULL)
		return (1);

	*number = 42;
	free(number);

	printf("%d\n", *number);

	return (0);
}
