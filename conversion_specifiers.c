#include "main.h"
/**
 * int_printf - print formatted output
 * @format:foramt string
 * Return: number of characters printed
 */
int int_printf(const char *format, ...)
{
	int printed = 0;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);

				printed += printf("%d", num);
			}
		}
		else
		{
			printed += printf("%c", *format);
		}
		format++;
	}

	va_end(args);
	return (printed);
}
