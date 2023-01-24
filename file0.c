#include "main.h"
#include <stdarg.h>

/**
 * _printf - write formated output to stdout
 * @format: the formated string to write to stdout
 * Return: the number of characters(bytes) written
 */

int _printf(const char *format, ...)
{
	int bytes_written, i = 0;
	va_list arg;

	if(format == NULL)
		return (-1);
	
	va_start(arg, format);

	for (; *format != '\0' && format; format++)
	{
		if (*format != '%')
		{
			bytes_written += write_char(*format);
			i++;
		}
		else
		{
			write_format(*format, arg, &bytes_written);
		}
	}
	va_end(arg);
	return (i);
}
