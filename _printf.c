#include "main.h"
#include <stdio.h>

/**
 * _printf - Prints output according to a format.
 * @format: A character string containing the format.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ....)
{
	va_list args;
	int count = 0;
	int buff_ind = 0;
	char buffer[1024];

	va_start(args, format);
	for (; *format != '\0'; format++)
	{
		if (*format != '%')
		{
			putchar(*format);
			count++;
		}
		else
		{
			format++;
			switch (*format)
			{
				case 'c':
					{
						int c = va_arg(args, int);
			
						putchar(c);
						count++;
						break;
					}
				case 's':
					{
						char *str = va_arg(args, char *);
				
						while (*str != '\0')
						{putchar(*str);
							str++;
							count++;
						}
						break;
					}
				case '%':
					{
						putchar('%');
						count++;
						break;
					}
				default:
					break;
			}
		}
	}
	va_end(args);
	return (count);
}

/**
 * print_buffer - Prints the buffer content and resets the buffer.
 * @buffer: The buffer containing the output.
 * @buff_ind: A pointer to the buffer index.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	for (int i = 0; i < *buff_ind; i++)
	{
		putchar(buffer[i]);
	}
	*buff_ind = 0;
}
