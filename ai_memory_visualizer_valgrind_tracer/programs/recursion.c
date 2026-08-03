#include <stdio.h>

void countdown(int number)
{
	int local_value;

	local_value = number * 10;
	printf("%d %d\n", number, local_value);

	if (number > 0)
		countdown(number - 1);
}

int main(void)
{
	countdown(3);

	return (0);
}
