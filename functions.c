#include "holberton.h"
#include <unistd.h> 

/**
 * print_char - Prints a character to the standard output.
 * @args: A va_list containing the character to print.
 * @buffer: The buffer to store the formatted output.
 * @flags: The flags for the conversion specifier.
 * @width: The field width for the conversion specifier.
 * @precision: The precision for the conversion specifier.
 * @size: A pointer to the size of the buffer.
 *
 * Return: The number of characters printed.
 */
int print_char(va_list args, char buffer[],
		int flags, int width, int precision, int *size)
{
	char c = va_arg(args, int);
	
	if (*size >= BUFFER_SIZE - 1)
	{
		write(1, buffer, *size);
		*size = 0;
	}
	if (!(flags & MINUS_FLAG))
	{
		while (width-- > 1)
		{
			buffer[(*size)++] = (flags & ZERO_FLAG) ? '0' : ' ';
			if (*size >= BUFFER_SIZE - 1)
			{
				write(1, buffer, *size);
				*size = 0;
			}
		}
	}
	buffer[(*size)++] = c;
	if (*size >= BUFFER_SIZE - 1)
	{
		write(1, buffer, *size);
		*size = 0;
	}
	if (flags & MINUS_FLAG)
	{
		while (width-- > 1)
		{
			buffer[(*size)++] = ' ';
			if (*size >= BUFFER_SIZE - 1)
			{
				write(1, buffer, *size);
				*size = 0;
			}
		}
	}
	return (1);
}
