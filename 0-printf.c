#include "main.h"
/**
 * _printf - function that produces output according to format
 * @format: format of the output
 * Return:  number of characters printed
*/
int _printf(const char *format, ...)
{
	va_list args;
	int chars_printed = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					chars_printed += print_char(va_arg(args, int));
					break;
				case 's':
					chars_printed += print_string(va_arg(args, char*));
					break;
				case '%':
					chars_printed += write(1, format, 1);
					break;
				default:
					break;
			}
		}
		else
		{
			chars_printed += write(1, format, 1);
		}
		format++;
	}

	va_end(args);

	return (chars_printed);
}

/**
 * print_char - print characters
 * @c: characters to be printed
 * Return: characters printed
*/
int print_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_string - prints string
 * @s: string to be printed
 * Return: string characters
*/
int print_string(char *s)
{
	int chars = 0;

	while (*s)
	{
		chars += write(1, s++, 1);
	}
	return (chars);
}
