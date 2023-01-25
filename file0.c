#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

/**
 * printIdentify - print ids
 * @ch: character after the %
 * @list: argument for the cr
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */

int printIdentify(char ch, va_list list)
{
	int j;

	identifyStruct functionPrint[] = {
		{"c", print_char},
		{"s", print_str},
		{NULL, NULL}
	};

	for (j = 0; functionPrint[j].cr != NULL; j++)
	{
		if (functionPrint[j].cr[0] == ch)
			return (functionPrint[j].printer(list));
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
	int i;
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

		print_special = printIdentify(format[i + 1], list);
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
