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
char *ch = va_arg(list, char*);

if (ch == NULL)
	ch = "(null)";
else if (*ch == '\0')
	return (-1);

for (i = 0; ch[i]; i++)
	_putchar(ch[i]);

return (i);
}