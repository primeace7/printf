#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - write formated output to stdout
 * @format: the formated string to write to stdout
 * Return: the number of characters(bytes) written
 */

void print_buffer(char buffer[], int *buff_ind);

int _printf(const char *format, ...)
{
	int i, printed_chars, buff_ind = 0;
	va_list list;
	char buffer[1024];

	if(format == NULL)
		return (-1);
	
	va_start(list, format);

	for(i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
