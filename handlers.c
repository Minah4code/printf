#include "main.h"
#include <stdio.h>

/**
 * write_unsgnd - Writes an unsigned integer to the buffer
 * @is_negative: Flag indicating if the number is negative
 * @ind: Index of the buffer
 * @buffer: The buffer to store the formatted string
 * @flags: Flags for special handling
 * @width: Field width
 * @precision: Precision
 * @size: Size of the buffer
 *
 * Return: The number of characters written
 */
int write_unsgnd(unsigned int num,
		int flags, int width, int precision, int size)
{
	int padding = width - num_digits;

	if (precision > ind)num_digits = precision;
	int padding = width - num_digits;

	if (is_negative)
	{
		buffer[ind] = '-';
		ind++;
		printed_chars++;
	}
	for (i = 0; i < padding; i++)
	{
		if (ind < size - 1)
		{
			buffer[ind] = ' ';
			ind++;
		}
		else
		{
			buffer[ind] = '\0';
			return (-1);
		}
	}
	for (i = 0; i < num_digits; i++)
	{
		if (ind < size - 1)
		{
			buffer[ind] = buffer[i];
			ind++;
			printed_chars++;
		}
		else
		{
			buffer[ind] = '\0';
			return (-1);
		}
	}
	buffer[ind] = '\0';
	return (printed_chars);
}
