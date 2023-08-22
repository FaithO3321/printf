#include "main.h"
/**
 * _printf - function that produces output according to format
 * @format: format of the output
 * Return:  number of characters printed
*/
int _printf(const char *format, ...)
{
	va_list args;
	char c;
	int chars_printed = 0;
	char *str = va_arg(args, char*);

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					chars_printed += write(1, &c, 1);
					break;
				case 's':
					if (!str)
					{
						str = "(null)";
					}
					chars_printed += write(1, str, strnlen(str, 10));
					free(str);
					break;
				case '%':
					chars_printed += write(1, "%", 1);
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
