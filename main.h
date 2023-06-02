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

int _printf(const char *format, ...);
int _putchar(char c);

typedef struct print
{
    char *t;
    int (*f)(va_list);
} print_t;

int _putchar(char c);
int print_char(va_list args);
int print_HEX(va_list args);
int print_string(char *str);
int print_percent(va_list args);
int print_integer(va_list args);
int print_unsigned_integer(va_list args);
int print_unsigned_number(unsigned int n);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_pointer(va_list args);
int print_reverse(va_list args);
int print_reversed(char *str)
int print_rot13(va_list args);
int print_rot13(char *str);
int print_rot13(char *s);
int print_string_rot13(va_list args);
int print_binary(unsigned int num);
int get_flags(const char *format, int *i);
int get_precision(const char *format, int *i, va_list list);
int write_unsgnd(unsigned int num, int flags, int width, int precision, int size);
int (*get_print_func(const char *format))(va_list);
int get_size(const char *format, int *i, va_list va);
int get_width(const char *format, int *i, va_list list);
int print_hex_number(unsigned int n, char *base);
long int convert_size_number(long int num, int size);
unsigned long int convert_size_unsgnd(unsigned long int num, int size);
int print_char(va_list args, char buffer[], int flags, int width, int precision, int size);
int print_pointer(va_list args, char buffer[], int flags, int width, int precision, int size);
int handle_print(const char *format, int *i, va_list args, char buffer[], int *index);
int print_hexa(va_list types, char map_to[], char buffer[], int flags, char flag_ch, int width, int precision, int size);

#endif
