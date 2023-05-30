#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * handle_print - Handles the printing of format specifiers
 * @fmt: The format specifier string
 * @ind: Pointer to the index of the buffer
 * @list: The va_list containing the arguments
 * @buffer: The buffer to store the formatted string
 * @flags: Flags for special handling
 * @width: Field width
 * @precision: Precision
 * @size: Size of the buffer
 *
 * Return: The number of characters printed
 */
int handle_print(const char *fmt, int *ind, va_list list,
		char buffer[], int flags, int width, int precision, int size)
{
	int printed_chars = 0;

	switch (*fmt)
	{
		case 'c':
			printed_chars = print_char(args)
				(list, buffer, flags, width, precision, size);
			break;
		case 's':
			printed_chars = print_string(args)
				(list, buffer, flags, width, precision, size);
			break;
		case 'd':
		case 'i':
			printed_chars = print_integer(args)
				(list, buffer, flags, width, precision, size);
			break;
		case 'u':
			printed_chars = print_unsigned
				(list, buffer, flags, width, precision, size);
			break;
		case 'o':
			printed_chars = print_octal
				(list, buffer, flags, width, precision, size);
			break;
		case 'x':
		case 'X':
			printed_chars = print_hexadecimal
				(list, buffer, flags, width, precision, size, (*fmt == 'X'));
			break;
		case 'b':
			printed_chars = print_binary
				(list, buffer, flags, width, precision, size);
			break;
		case 'S':
			printed_chars = print_custom_string
				(list, buffer, flags, width, precision, size);
			break;
		case 'p':
			printed_chars = print_pointer
				(list, buffer, flags, width, precision, size);
			break;
		case 'r':
			printed_chars = print_reversed
				(list, buffer, flags, width, precision, size);
			break;
		case 'R':
			printed_chars = print_rot13
				(list, buffer, flags, width, precision, size);
			break;
		default:
			printed_chars = print_unknown_specifier
				(buffer, *ind, fmt, flags, width, size);
			(*ind)++;
			break;
	}
	return (printed_chars);
}
