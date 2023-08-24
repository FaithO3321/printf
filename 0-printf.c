#include "main.h"
/**
 * print_char - prints character specifier
 * @args: arguments
 * Return: number of characters printed
*/
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}

/**
 * print_string - prints string specifier
 * @args: arguments
 * Return: number of characters in the string
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char*);
	int len = 0;

	while (str[len])
	{
		len++;
	}
	return (write(1, str, len));
}

/**
 * _printf - function that produces output according to format
 * @format: format of the output
 * Return:  number of characters printed
*/
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	int i;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					printed_chars += print_char(args);
					break;
				case 's':
					printed_chars += print_string(args);
					break;
				case '%':
					printed_chars += write(1, &format[i], 1);
					break;
			}
		}
		else
		{
			printed_chars += write(1, &format[i], 1);
		}
	}

	va_end(args);

	return (printed_chars);
}




