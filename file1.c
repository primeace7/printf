#include "main.h"

/**
 * print_char - Prints a char to the standard output
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * Return: Number of chars printed
 */
int print_char(va_list types, char buffer[])
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer));
}

/**
 * print_string - Prints a string
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * Return: Number of chars printed
 */
int print_string(va_list types, char buffer[])
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);

	if (str == NULL)
	{
		str = "(null)";
	}

	while (str[length] != '\0')
		length++;

	return (write(1, str, length));
}
/**
 * print_percent - Prints a percent sign
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * Return: Number of chars printed
 */
int print_percent(va_list types, char buffer[])
{
	UNUSED(types);
	UNUSED(buffer);
	return (write(1, "%%", 1));
}

