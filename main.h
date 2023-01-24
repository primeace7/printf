#ifndef _PRINT_H_
#define _PRINT_H_

#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>
int _printf(const char *format, ...);
int slen(char *);
void write_format(char, va_list arg, int *);
int write_char(char str);
void write_string(char *, int);
#endif
