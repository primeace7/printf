#include "main.h"

/**
 * _printf - write formated output to stdout
 * @format: the formated string to write to stdout
 * Return: the number of characters(bytes) written
 */

int _printf(const char *format, ...)
{
	int bytes_written;
	va_list arg;

	if(format == NULL)
	{
		return (-1);
	}
	
	va_start(arg, format);

	for (; *format != '\0' && format != NULL; format++)
	{
		for (; *format != '%'; format++)
			bytes_written += write_char(*format);
		if (*format == '%')
		{
			format++;
			write_format(*format, arg, &bytes_written);
		}
	}
	va_end(arg);
	return (bytes_written);
}
