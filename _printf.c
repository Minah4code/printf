#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <unistd.h>

int handle_print(const char *format, int *i,
va_list args, char buffer[], int width, int precision, int flags, int size);

/**
 * _printf - Produces output according to a format.
 * @format: A character string containing zero or more directives.
 *
 * Return: The number of characters printed.
 */

int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	int count = 0;

	while (*format != '\0')
	{
	if (*format == '%')
	{
	format++;
	switch (*format)
	{
	case 'c':
	count += putchar(va_arg(args, int));
	break;
	case 's':
	count += printf("%s", va_arg(args, char *));
	break;
	case '%':
	count += putchar('%');
	break;
	case 'd':
	case 'i':
	count += printf("%d", va_arg(args, int));
	break;
	case 'u':
	count += printf("%u", va_arg(args, unsigned int));
	break;
	case 'o':
	count += printf("%o", va_arg(args, unsigned int));
	break;
	case 'x':
	count += printf("%x", va_arg(args, unsigned int));
	break;
	case 'X':
	count += printf("%X", va_arg(args, unsigned int));
	break;
	case 'p':
	count += printf("%p", va_arg(args, void *));
	break;
	case 'b':
	count += print_binary(va_arg(args, unsigned int));
	break;
	case 'S':
	count += print_string(va_arg(args, char *));
	break;
	case 'r':
	count += print_reversed(va_arg(args, char *));
	break;
	case 'R':
	count += print_rot13(va_arg(args, char *));
	break;
	default:
	count += putchar('%');
	count += putchar(*format);
	break;
	}
	}
	else
	{
		putchar(*format);
		count++;
	}
	format++;
	}
	va_end(args);
	return (count);
}
/**
 * Prints the binary representation of an unsigned integer.
 *
 * @param num The unsigned integer to be printed in binary.
 * @return The number of characters printed.
 */
int print_binary(unsigned int num)
{
	if (num == 0)
	{
		putchar('0');
		return (1);
	}
	int count = 0;
	unsigned int mask = 1 << (sizeof(unsigned int) * 8 - 1);

	while (mask > 0)
	{
		if (num & mask)
			count += putchar('1');
		else
			count += putchar('0');
		mask >>= 1;
	}
	return (count);
}
/**
 * Prints a null-terminated string.
 *
 * @param str The string to be printed.
 * @return The number of characters printed.
 */
int print_string(char *str)
{
	int count = 0;

	while (*str != '\0')
	{
		if (*str < 32 || *str >= 127)
		{
			count += printf("\\x%02X", (unsigned char)*str);
		}
		else
		{
			count += putchar(*str);
		}
		str++;
	}
	return (count);
}
/**
 * Prints a null-terminated string in reverse order.
 *
 * @param str The string to be printed in reverse.
 * @return The number of characters printed.
 */

int print_reversed(char *str)
{
	int count = 0;

	if (*str == '\0')
		return (count);
	count += print_reversed(str + 1);
	count += putchar(*str);
	return (count);
}
/**
 * Prints the ROT13 encoded version of a null-terminated string.
 *
 * @param str The string to be encoded and printed.
 * @return The number of characters printed.
 */

int print_rot13(char *str)
{
	int count = 0;

	while (*str != '\0')
	{
		char c = *str;

		if ((c >= 'a' && c <= 'm') || (c >= 'A' && c <= 'M'))
			count += putchar(c + 13);
		else if ((c >= 'n' && c <= 'z') || (c >= 'N' && c <= 'Z'))
			count += putchar(c - 13);
		else
			count += putchar(c);
		str++;
	}
	return (count);
}
