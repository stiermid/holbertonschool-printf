#include "main.h"

/**
 * print_string - prints string
 * @args: arguments
 *
 * Return: number of bytes printed
 * On error, -1 is returned.
 */
int print_string(va_list *args)
{
	char *str = va_arg(*args, char *);
	int i = 0;

	if (!str)
		str = "(null)";

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}

	return (i);
}

