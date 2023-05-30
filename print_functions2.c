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
/**
 * print_string - Prints a string of characters.
 * @args: A va_list containing the string to be printed.
 *
 * Return: The number of characters printed.
 */
int print_string(va_list args)
{
        char *str = va_arg(args, char *);
        int count = 0;

        if (str == NULL)
                str = "(null)";

        while (*str)
        {
                _putchar(*str);
                str++;
                count++;
        }

        return count;
}
/**
 * print_string_reverse - Prints
 * a string of characters in reverse.
 * @args: A va_list containing the string to be printed.
 *
 * Return: The number of characters printed.
 */
int print_string_reverse(va_list args)
{
        int count = 0;
        char *str = va_arg(args, char *);

        if (str == NULL)
                str = "(null)";

        count = _print_rev_recursion(str);

        return (count);
}

/**
 * _print_rev_recursion - Prints
 * a string in reverse recursively.
 * @s: The string to be printed.
 *
 * Return: The number of characters printed.
 */
int _print_rev_recursion(char *s)
{
        int count = 0;

        if (*s)
        {
                count += _print_rev_recursion(s + 1);
                _putchar(*s);
                count++;
        }

        return (count);
}


/**
 * print_string_rot13 - Prints a string of
 * characters using the ROT13 cipher.
 * @args: A va_list containing the string to be printed.
 *
 * Return: The number of characters printed.
 */
int print_string_rot13(va_list args)
{
        int count = 0;
        char *str = va_arg(args, char *);

        if (str == NULL)
                str = "(null)";

        count = print_rot13(str);

        return (count);
}

/**
 * print_rot13 - Prints a string using the ROT13 cipher.
 * @s: The string to be printed.
 *
 * Return: The number of characters printed.
 */
int print_rot13(char *s)
{
        int count = 0;
        int i;
        char *input = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        char *output = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

        for (i = 0; s[i]; i++)
        {
                if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
                {
                        int index = 0;
                        while (input[index])
                        {
                                if (s[i] == input[index])
                                {
                                        _putchar(output[index]);
                                        count++;
                                        break;
                                }
                                index++;
                        }
                }
                else
                {
                        _putchar(s[i]);
                        count++;
                }
        }

        return (count);
}
