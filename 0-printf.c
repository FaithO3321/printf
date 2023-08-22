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
					chars_printed += printf("%c", va_arg(args, int));
					break;
				case 's':
					chars_printed += printf("%s", va_arg(args, char*));
					break;
				case '%':
					chars_printed += printf("%%");
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
