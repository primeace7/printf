#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list list);
int print_persent(va_list list);
int print_str(va_list list);
int print_unsigned(va_list list);
int print_int(va_list list);
/**
 * struct identifierStruct - structure definition of a printTypeStruct
 * @xy: type
 * @printer: function to print
 */
typedef struct identifierStruct
{
char *xy;
int (*printer)(va_list);
} identifierStruct;

#endif
