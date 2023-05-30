#include "main.h"


/**
 * print_pointer - Prints
 * a pointer address in hexadecimal format
 * @types: The argument list passed to the function
 * @buffer: The buffer to store the formatted string
 * @flags: The formatting flags
 * @width: The field width
 * @precision: The precision value
 * @size: The size of the buffer
 *
 * Return: The number of characters printed
 */
int print_pointer(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	void *ptr = va_arg(types, void *);

	if (ptr == NULL)
		return (handle_null_pointer
			(buffer, flags, width, precision, size));
	return (write_pointer
			(ptr, buffer, flags, width, precision, size));
}
