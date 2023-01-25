#ifndef ABIY_H
#define ABIY_H

#include <stdarg.h>

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list list);
int print_str(va_list list);
int print_percent(void);

/**
 * struct id_Str - definition ...
 * @cr: type
 * @printer: function to print
 */
typedef struct id_Str
{
char *cr;
int (*printer)(va_list);
} id_Str;

#endif
