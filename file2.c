#include "abiy.h"
/**
 * p_func1 - writes chars after a % if they
 * don't match anything in the struct
 * @c1: the first char passed (always %)
 * @c2: the char after the %
 * Return: 1 if ch2 is a % and 2 is ch2 is anything else
 */

int p_func1(char c1, char c2)
{
	if (c2 == '%')
	{
		write(1, &c2, 1);
		return (1);
	}
	else
	{
		write(1, &c1, 1);
		write(1, &c2, 1);
		return (2);
	}
}
