#include "main.h"

/**
 * print_string_rot13 - Prints a string of characters using the ROT13 cipher.
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
