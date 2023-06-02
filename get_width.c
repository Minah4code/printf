#include "main.h"

/**
 * get_width - Extracts the width from the format string.
 * @format: The format string.
 * @i: A pointer to the current position in the format string.
 * @list: The va_list containing the arguments.
 *
 * Return: The width value, or 0 if no width is specified.
 */
int get_width(const char *format, int *i, va_list list)
{
	int width = 0;

	while (format[*i] >= '0' && format[*i] <= '9')
	{
		width = (width * 10) + (format[*i] - '0');
		(*i)++;
	}
	if (format[*i] == '*')
	{
		width = va_arg(list, int);
		(*i)++;
	}
	return (width);
}
