#include "main.h"

/**
 * Writes the formatted output for an unsigned integer.
 * @param num The unsigned integer to be printed.
 * @param flags Flags for formatting options.
 * @param width Minimum field width for printing.
 * @param precision Precision for printing.
 * @param size Size modifier for the argument.
 * @return The number of characters printed.
*/

int write_unsgnd(unsigned int num, int flags, int width, int precision, int size)
{
	int num_digits = get_num_digits(num);
	int printed_chars = 0;
	int is_negative = 0;
	int i;
	int padding = width - num_digits;

	if (precision > num_digits)
		num_digits = precision;
	padding = width - num_digits;
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
