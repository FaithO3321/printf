#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int print_string(va_list args);
int print_char(va_list args);
int _putchar(char c);
int print_number(int n);
int _printf(const char *format, ...);

#endif /* MAIN_H */
