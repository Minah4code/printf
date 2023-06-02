<<<<<<< HEAD
=======
#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 44

>>>>>>> e0d1751b818a970d5f1d01eaeb69feb951d661b9
int _printf(const char *format, ...);
int _putchar(char c);

/**
 * struct print - Struct print
 *
 * @t: The format to print
 * @f: The function to print
 */
typedef struct print
{
    char *t;
    int (*f)(va_list);
} print_t;

int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_integer(va_list args);
int print_unsigned_integer(va_list args);
int print_octal(va_list args);
int print_hexadecimal(va_list args);
int print_hexadecimal_upper(va_list args);
int print_pointer(va_list args);
int print_reverse(va_list args);
int print_rot13(va_list args);
int write_unsgnd(unsigned int num, int flags, int width, int precision, int size);
int (*get_print_func(const char *format))(va_list);
int get_size(const char *format, int *i, va_list va);
int print_char(va_list args, char buffer[], int flags, int width, int precision, int size);
int print_pointer(va_list args, char buffer[], int flags, int width, int precision, int size);
int handle_print(const char *format, int *i, va_list args, char buffer[], int *index);

#endif /* MAIN_H */
