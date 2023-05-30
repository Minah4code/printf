#include "main.h"
#include <unistd.h>

int print_buffer(char *buffer, int size);

/**
 * _printf - Produces output according to a format.
 * @format: A character string
 * containing zero or more directives.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
    int printed_chars = 0;
    va_list args;
    char buffer[1024];
    int i = 0;
    int j = 0;

    va_start(args, format);
    while (format && format[i])
    {
	    if (format[i] == '%')
	    {
		    i++;
		    if (format[i] == '\0')
			    return (-1);
		    j = handle_print(format, &i, args,
				    buffer, 0, 0, 0, 1024);
		    if (j == -1)
			    return (-1);
		    printed_chars += j;
	    }
	    else
	    {
		    buffer[0] = format[i];
		    buffer[1] = '\0';
		    write(1, buffer, 1);
		    printed_chars++;
	    }
	    i++;
    }
    va_end(args);
    return (printed_chars);
}
/**
 * print_buffer - Prints the contents of the buffer.
 * @buffer: A pointer to the buffer containing the characters to be printed.
 * @size: The number of characters in the buffer.
 *
 * Return: The total number of characters printed.
 */
int print_buffer(char *buffer, int size)
{
	int total_chars_printed = 0;
	int chars_written = 0;
	int chars_left = size;
	char *current_position = buffer;

	while (chars_left > 0)
	{
		chars_written = write(1, current_position, chars_left);
		if (chars_written <= 0)
			return (-1);
		total_chars_printed += chars_written;
		chars_left -= chars_written;
		current_position += chars_written;
	}
	return (total_chars_printed);
}
