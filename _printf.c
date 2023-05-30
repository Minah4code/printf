#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);
				int temp = num;
				int len = 0;
				char buffer[20];

				if (temp == 0)
				{
					buffer[len++] = '0';
				}
				else
				{
					if (temp < 0)
					{
						write(1, "-", 1);
						printed_chars++;
						temp = -temp;
					}
					while (temp != 0)
					{
						int digit = temp % 10;
						buffer[len++] = '0' + digit;
						temp /= 10;
					}
				}
				while (len > 0)
				{
					write(1, &buffer[len - 1], 1);
					printed_chars++;
					len--;
				}
			}
		}
		else
		{
			write(1, format, 1);
			printed_chars++;
		}
		format++;
	}
	va_end(args);
	return (printed_chars);
}
