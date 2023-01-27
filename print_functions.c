#include "main.h"
#include <stdio.h>
/**
 * print_char - writes the character c to stdout
 * @list: argument
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int print_char(va_list list)
{
	char c = va_arg(list, int);
	return (_putchar(c));
}

/**
 * print_str - prints a string with a `s`
 * @list: argument
 * Return: number of character printed
 */

int print_str(va_list list)
{
unsigned long long i;

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

/**
 * print_int - prints an integer.
 * @list: argument
 * Return: 0
 */

int print_int(va_list list)
{

unsigned int q = 1, i, w, r = 0;
int n = va_arg(list, int);

if (n < 0)
{
	_putchar('-');
	r++;
	n *= -1;
}

for (i = 0; n / q > 9; i++, q *= 10)
;

for (; q >= 1; n %= q, q /= 10, r++)
{
	w = n / q;
	_putchar('0' + w);
}
return (r);
}
