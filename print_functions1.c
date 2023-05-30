#include "main.h"

/**
 * print_hexa - Prints an unsigned
 * decimal number in hexadecimal format
 *
 * @types: The argument list passed to the function
 * @map_to: The mapping
 * characters for hexadecimal conversion
 *
 * @buffer: The buffer to store the formatted string
 * @flags: The formatting flags
 * @flag_ch: The flag character
 * @width: The field width
 * @precision: The precision value
 * @size: The size of the buffer
 *
 * Return: The number of characters printed
 */
int print_hexa(va_list types, char map_to[], char buffer[], int flags,
		char flag_ch, int width, int precision, int size)
{
	unsigned int num = va_arg(types, unsigned int);

	return (write_unsgnd
		(0, num, buffer, flags, width, precision, size));
}
