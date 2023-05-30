#include "main.h"

/**
 * get_size - Parses the
 * size field from the format string
 *
 * @format: The format string
 * @i: Pointer to the current
 * index in the format string
 *
 * Return: The size value
 */
int get_size(const char *format, int *i, va_list va)
{
	int size = 0;

	if (format[*i] == '*')
	{
		size = va_arg(va, int);
		(*i)++;
	}
	else
	{
		while (_isdigit(format[*i]))
		{
			size = (size * 10) + (format[*i] - '0');
			(*i)++;
		}
	}
	return (size);
}
