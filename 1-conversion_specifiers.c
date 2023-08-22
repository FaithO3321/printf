#include "main.h"
/**
 * int_printf - function that produces output according to format
 * @format: format of the output
 * Return:  number of characters printed
*/
int int_printf(const char *format, ...)
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
					chars_printed += printf("%c", va_arg(args, int));
					break;
				case 's':
					chars_printed += printf("%s", va_arg(args, char*));
					break;
				case '%':
					chars_printed += printf("%%");
					break;
				case 'd':
					chars_printed += printf("%d", va_arg(args, int));
					break;
				case 'i':
					chars_printed += printf("%i", va_arg(args, int));
					break;
			}
		}
		else
		{
			chars_printed += printf("%c", *format);
		}

		format++;
	}

	va_end(args);

	return (chars_printed);
}

/**
 * print_int - print integer
 * @n: integer to be printed
 * Return: string length
*/
int print_int(int n)
{
	char str[10];

	sprintf(str, "%d", n);

	return (write(1, str, strlen(str)));
}
