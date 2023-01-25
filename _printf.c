#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_ids - print ids
 * @ch1: character after the %
 * @list: argument for the cr
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */

int print_ids(char ch1, va_list list)
{
	int func_i;

	id_Str func_list[] = {
		{"c", print_char},
		{"s", print_str},
		{NULL, NULL}
	};

	for (func_i = 0; func_list[func_i].cr != NULL; func_i++)
	{
		if (func_list[func_i].cr[0] == ch1)
			return (func_list[func_i].printer(list));
	}
	return (0);
}

/**
 * _printf - mimic printf from stdio
 * Description: produces output according to a format
 * write output to stdout, the standard output stream
 * @format: character string composed of zero or more directives
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 * return -1 for error
 */

int _printf(const char *format, ...)
{
	unsigned int i;
	int print_special = 0, printed_char = 0;
	va_list list;

	va_start(list, format);
	if (format == NULL)
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			printed_char++;
			continue;
		}
		if (format[i + 1] == '%')
		{
			_putchar('%');
			printed_char++;
			i++;
			continue;
		}
		if (format[i + 1] == '\0')
			return (-1);

		print_special = print_ids(format[i + 1], list);
		if (print_special == -1 || print_special != 0)
			i++;
		if (print_special > 0)
			printed_char += print_special;

		if (print_special == 0)
		{
			_putchar('%');
			printed_char++;
		}
	}
	va_end(list);
	return (printed_char);
}
