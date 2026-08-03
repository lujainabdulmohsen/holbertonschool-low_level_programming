#include <stdlib.h>

int main(void)
{
	int *numbers;

	numbers = malloc(sizeof(int) * 5);
	if (numbers == NULL)
		return (1);

	numbers[0] = 10;

	return (0);
}
