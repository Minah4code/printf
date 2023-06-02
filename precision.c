#include "main.h"
#include <stdio.h>

/**
 * get_precision - Retrieves the precision from the format string
 * @format: The format string
 * @i: Pointer to the current index in the format string
 * @list: The va_list of arguments
 *
 * Return: The precision value
 */
int get_precision(const char *format, int *i, va_list list)
{
	int precision = 0;

	if (format[*i] == '.')
	{
		*i += 1;
		if (format[*i] == '*')
		{
			precision = va_arg(list, int);
			*i += 1;
		}
		else
		{
			while (format[*i] >= '0' && format[*i] <= '9')
			{
				precision = (precision * 10) + (format[*i] - '0');
				*i += 1;
			}
		}
	}
	return (precision);
}
