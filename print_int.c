#include "main.h"

/**
 * print_int - prints integer
 * @args: arguments
 *
 * Return: number of bytes printed
 * On error, -1 is returned.
 */
int print_int(va_list *args)
{
	int num = va_arg(*args, int);
	int divisor = 1;
	int count = 0;
	char c;
	
	if (num == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return (11);
	}

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
		count++;
	}

	while (num / divisor >= 10)
	{
		divisor *= 10;
	}

	while (divisor > 0)
	{
		c = ((num / divisor) % 10) + '0';
		write(1, &c, 1);
		count++;
		divisor /= 10;
	}

	return (count);
}

