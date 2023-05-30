#include "main.h"

/**
 * print_hexa - Prints an unsigned
 * decimal number in hexadecimal format
 *
 * @types: The argument list passed to the function
 * @map_to: The mapping
 * characters for hexadecimal conversion
 *
 * @buffer: The buffer to store the formatted string
 * @flags: The formatting flags
 * @flag_ch: The flag character
 * @width: The field width
 * @precision: The precision value
 * @size: The size of the buffer
 *
 * Return: The number of characters printed
 */
int print_hexa(va_list types, char map_to[], char buffer[], int flags,
		char flag_ch, int width, int precision, int size)
{
	unsigned int num = va_arg(types, unsigned int);

	return (write_unsgnd
		(0, num, buffer, flags, width, precision, size));
}
/**
 * print_unsigned - Prints an unsigned integer number.
 * @args: A va_list containing the
 * unsigned integer number to be printed.
 *
 * Return: The number of characters printed.
 */
int print_unsigned(va_list args)
{
        unsigned int num = va_arg(args, unsigned int);
        int count = 0;

        count += print_unsigned_number(num);

        return (count);
}

/**
 * print_unsigned_number - Recursive
 * helper function to print an unsigned number.
 * @n: The number to be printed.
 *
 * Return: The number of characters printed.
 */
int print_unsigned_number(unsigned int n)
{
        int count = 0;

        if (n / 10)
                count += print_unsigned_number(n / 10);

        _putchar((n % 10) + '0');
        count++;

        return (count);
}
/**
 * print_hex - Prints a hexadecimal number (lowercase).
 * @args: A va_list containing
 * the hexadecimal number to be printed.
 *
 * Return: The number of characters printed.
 */
int print_hex(va_list args)
{
        unsigned int num = va_arg(args, unsigned int);
        int count = 0;

        count += print_hex_number
		(num, "0123456789abcdef");

        return (count);
}

/**
 * print_hex_number - Recursive helper
 * function to print a hexadecimal number.
 * @n: The number to be printed.
 * @base: The base digits for the
 * hexadecimal number (e.g., "0123456789abcdef").
 *
 * Return: The number of characters printed.
 */
int print_hex_upper(unsigned int n, char *base)
{
        int count = 0;

        if (n / 16)
                count += print_hex_upper(n / 16, base);

        _putchar(base[n % 16]);
        count++;

        return (count);
}
/**
 * print_HEX - Prints a hexadecimal number (uppercase).
 * @args: A va_list containing the hexadecimal number to be printed.
 *
 * Return: The number of characters printed.
 */
int print_HEX(va_list args)
{
        unsigned int num = va_arg(args, unsigned int);
        int count = 0;

        count += print_hex_upper(num, "0123456789ABCDEF");

        return (count);
}

