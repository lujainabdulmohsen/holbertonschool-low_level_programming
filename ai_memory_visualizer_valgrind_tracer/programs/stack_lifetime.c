#include <stdio.h>

void inspect(void)
{
	int value;
	int *pointer;

	value = 42;
	pointer = &value;
	printf("value=%d\n", value);
	*pointer = 84;
	printf("value=%d\n", value);
}

int main(void)
{
	int main_value;

	main_value = 10;
	printf("main_value=%d\n", main_value);
	inspect();
	printf("main_value=%d\n", main_value);

	return (0);
}
