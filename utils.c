#include "main.h"

/**
 * _putchar - Writes a character to stdout.
 * @c: The character to write.
 *
 * Return: On success, the number of characters written.
 * On error, -1 is returned.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * convert_size_number - Converts a
 * signed number to the specified size
 * @num: The number to convert
 * @size: The size to convert to
 *
 * Return: The converted number
 */
long int convert_size_number(long int num, int size)
{
	if (size == 0)
		return (num);
	if (size == 'h')
		return ((short)num);
	if (size == 'l')
		return ((long int)num);
	if (size == 'L')
		return ((long int)num);
	return (num);
}

/**
 * convert_size_unsgnd - Converts an
 * unsigned number to the specified size
 * @num: The number to convert
 * @size: The size to convert to
 *
 * Return: The converted number
 */
unsigned long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == 0)
		return (num);
	if (size == 'h')
		return ((unsigned short)num);
	if (size == 'l')
		return ((unsigned long int)num);
	if (size == 'L')
		return ((unsigned long int)num);
	return (num);
}
}
