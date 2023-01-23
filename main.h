#ifndef _PRINT_H_
#define _PRINT_H_

#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>
int _printf(const char *format, ...);
int string_len(char *);
int format_string(char *, va_list arg);
#endif
