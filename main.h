#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list list);
int print_str(va_list list);
/**
 * struct identifyStruct - definition ...
 * @cr: type
 * @printer: function to print
 */
typedef struct identifyStruct
{
char *cr;
int (*printer)(va_list);
} identifyStruct;

#endif
