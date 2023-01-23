#include "main.h"

/**
 * _printf - print any input according to a specified format
 * @format: the format to use in printing
 * Return: the number of characters printed, excluding string
 * null bytes
 */

int _printf(const char *format, ...)
{
	va_list arg, save;
	int bytes_written;
	char *fmt;

	va_start(arg, format);
	bytes_written = 0;
	fmt = (char *)format;

	for (; *fmt != '\0' && format != NULL; fmt ++)
	{
		while (*fmt != '%')
		{
			bytes_written += write(1, fmt, sizeof(char));
			fmt += sizeof(char);
		}
		if (*fmt == '%')
		{
			fmt += sizeof(char);
			bytes_written += format_string(fmt, arg);
		}

	}
	return (bytes_written);
}

/**
 * format_string - print an argument according to input format
 * @str: the input format character
 * @arg: a va_list variable to get the next variable argument
 * Return: the number of bytes printed
 */

int format_string(char *str, va_list arg)
{
	int count, str_len, cha;
	char *ch;

	count = 0;

	switch (*str)
	{
	case 'c':
	{
		cha = va_arg(arg, int);
		count += write(1, &cha, 4);
		break;
	}
	case 's':
	{
		ch = va_arg(arg, char *);
		str_len = string_len(ch);
		count += write(1, ch, str_len);
		break;
	}
	case '%':
		count += write(1, "%", sizeof(char));
		break;
	}
	return (count);
}

/**
 * string_len - find the length of a string
 * @str: pointer to the string which length is required
 * Return: the lenght of the input string
 */

int string_len(char *str)
{
	if (*str == '\0' || str == NULL)
		return (0);
	return (sizeof(char) + string_len(str + 1));
}
