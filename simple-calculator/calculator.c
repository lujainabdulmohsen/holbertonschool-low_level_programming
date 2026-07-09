#include <stdio.h>

int read_number(char *label, int *number)
{
	int result;
	int c;

	while (1)
	{
		printf("%s", label);
		result = scanf("%d", number);

		if (result == 1)
		{
			return (1);
		}

		printf("Invalid number\n");

		while ((c = getchar()) != '\n' && c != EOF)
		{
		}
	}
}

int main(void)
{
	int choice;
	int a;
	int b;
	int result;
	int c;

	choice = -1;

	while (choice != 0)
	{
		printf("Simple Calculator\n");
		printf("1) Add\n");
		printf("2) Subtract\n");
		printf("3) Multiply\n");
		printf("4) Divide\n");
		printf("0) Quit\n");
		printf("Choice: ");

		result = scanf("%d", &choice);

		if (result != 1)
		{
			printf("Invalid choice\n");

			while ((c = getchar()) != '\n' && c != EOF)
			{
			}

			continue;
		}

		if (choice == 0)
		{
			printf("Bye!\n");
		}
		else if (choice >= 1 && choice <= 4)
		{
			read_number("A: ", &a);
			read_number("B: ", &b);

			if (choice == 1)
			{
				printf("Result: %d\n", a + b);
			}
			else if (choice == 2)
			{
				printf("Result: %d\n", a - b);
			}
			else if (choice == 3)
			{
				printf("Result: %d\n", a * b);
			}
			else if (b == 0)
			{
				printf("Error: division by zero\n");
			}
			else
			{
				printf("Result: %.1f\n", (double)a / b);
			}
		}
		else
		{
			printf("Invalid choice\n");
		}
	}

	return (0);
}
