#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * printIdentifiers - print identify
 * @next: character after the %
 * @list: argument for the cr
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */

int printIdentifiers(char next, va_list list)
{
	int j;

	identifierStruct functionPrint[] = {
		{"c", print_char},
		{"s", print_str},
		{"u", print_unsigned},
		{NULL, NULL}
	};

	for (j = 0; functionPrint[j].xy != NULL; j++)
	{
		if (functionPrint[j].xy[0] == next)
				return (functionPrint[j].printer(list));
	}
	return (0);
}

/**
 * _printf - printf function 
 * Description: produces output according to a format
 * @format: character string composed of zero or more directives
 * 
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 * return -1 for incomplete identifier error
 */

int _printf(const char *format, ...)
{
	unsigned int i;
	int a = 0, b = 0;
	va_list list;

	va_start(list, format);
	if (format == NULL)
			return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			b++;
			continue;
		}
		if (format[i + 1] == '%')
		{
			_putchar('%');
			b++;
			i++;
			continue;
		}
		if (format[i + 1] == '\0')
				return (-1);

		a = printIdentifiers(format[i + 1], list);

		if (a == -1 || a != 0)
				i++;
		if (a > 0)
				b += a;

		if (a == 0)
		{
			_putchar('%');
			b++;
		}
	}
	va_end(list);
	return (b);
}
