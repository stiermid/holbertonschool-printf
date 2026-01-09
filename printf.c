#include "main.h"

/**
 * _printf - printf
 * @format: character string
 *
 * Return: the number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;
	int count = 0;

	if (!format)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '\0')
		{
			va_end(args);
			return (-1);
		}

		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (format[i] == 'c')
			{
				count += print_char(&args);
			}
			else if (format[i] == 's')
			{
				count += print_string(&args);
			}
			else if (format[i] == 'i' || format[i] == 'd')
			{
				count += print_int(&args);
			}
			else if (format[i] == '%')
			{
				write(1, "%", 1);
				count++;
			}
			else
			{
				write(1, "%", 1);
				write(1, &format[i], 1);
				count += 2;
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}

	va_end(args);
	return (count);
}

