#include "main.h"
#include <unistd.h>
#include <stdio.h>
/**
 * print_char - writes the character c to stdout
 * @list: argument
 * Return: On success 1.
 * On error, -1,
 */
int print_char(va_list list)
{
	return (_putchar(va_arg(list, int)));
}

/**
 * print_str - prints a string with a `s`
 * @list: argument
 * Return: number of character printed
 */
int print_str(va_list list)
{
int i;
char *ch2 = va_arg(list, char*);

if (ch2 == NULL)
	ch2 = "(null)";
else if (*ch2 == '\0')
	return (-1);

for (i = 0; ch2[i]; i++)
	_putchar(ch2[i]);

return (i);
}