#include "main.h"
#include <stdarg.h>

/**
 * _printf - write formated output to stdout
 * @format: the formated string to write to stdout
 * Return: the number of characters(bytes) written
 */

int _printf(const char *format, ...)
{
	int bytes_written, i;
	va_list arg;

	if(format == NULL)
		return (-1);
	
	va_start(arg, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			bytes_written += write_char(*format);
		}
		else
		{
			write_format(*format, arg, &bytes_written);
			i++;
		}
	}
	va_end(arg);
	return (bytes_written);
}
