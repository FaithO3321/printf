#include "main.h"
/**
 * _printf - print formatted output
 * @format:foramt string
 * Return: number of characters printed
 * excluding the null byte
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0, i;

	va_start(args, format);

	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'd':
				case 'i':
					printed_chars += print_number(va_arg(args, int));
					break;
				default:
					_putchar('%');
					_putchar(format[i]);
					printed_chars += 2;
					break;
			}
		}
		else
		{
			_putchar(format[i]);
			printed_chars++;
		}
	}

	va_end(args);

	return (printed_chars);
}

/**
 * _putchar - writes characters to stdout
 * @c: the character to print
 * Return: number of characters printed, -1 on error
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_number - prints number to stdout
 * @n: number to be printed
 * Return: number of characters printed
 */
int print_number(int n)
{
	unsigned int num;
	int printed_chars = 0;

	if (n < 0)
	{
		_putchar('-');
		printed_chars++;
		num = -n;
	}
	else
		num = n;
	if (num / 10)
		printed_chars += print_number(num / 10);

	_putchar((num % 10) + '0');
	printed_chars++;

	return (printed_chars);
}

