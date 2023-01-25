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

char *str = va_arg(list, char*);

if (str == NULL)
		str = "(null)";
else if (*str == '\0')
		return (-1);

for (i = 0; str[i]; i++)
		_putchar(str[i]);

return (i);
}

/**
 * print_unsigned - prints an unsigned int.
 * @list: argument
 * Return: 0
 */

int print_unsigned(va_list list)
{
int z = 1, i, x;
unsigned int n = va_arg(list, unsigned int);

for (i = 0; n / z > 9; i++, z *= 10)
;

for (; z >= 1; n %= z, z /= 10)
{
	x = n / z;
	_putchar('0' + x);
}
return (i + 1);
}