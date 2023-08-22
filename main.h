#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int print_char(char c);
int print_string(char *s);
int _putchar(char c);
int print_number(int n);
int _printf(const char *format, ...);
int int_printf(const char *format, ...);

#endif /* MAIN_H */
