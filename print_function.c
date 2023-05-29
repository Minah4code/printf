#include "main.h"

/**
 * print_char - Prints a single character
 * @types: The va_list containing the character argument
 * @buffer: The buffer to store the formatted output
 * @flags: The flags for formatting
 * @width: The width of the field
 * @precision: The precision of the field
 * @size: The total size of the buffer
 *
 * Return: The number of characters printed
 */
int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char ch = va_arg(types, int);
	int count = 0;

	if (width > 0 && !(flags & FLAG_MINUS))
	{
		while (count < width - 1)
		{
			buffer[size++] = ' ';
			count++;
		}
	}
	buffer[size++] = ch;
	count++;
	if (width > 0 && (flags & FLAG_MINUS))
	{
		while (count < width)
		{
			buffer[size++] = ' ';
			count++;
		}
	}
	return (count);
}
