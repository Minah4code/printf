#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZE */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	chaer fmt;
	int (*fn)(va_list, car[], int, int, int, int);
}
/* Function Prototypes */
int _printf(const char *format, ...);
int print_char(va_list args, char buffer[], int flags, int width, int precision, int size);
int print_string(va_list args, char buffer[], int flags, int width, int precision, int size);
int print_decimal(va_list args, char buffer[], int flags, int width, int precision, int size);
int print_unsigned(va_list args, char buffer[], int flags, int width, int precision, int size);
int print_hex(va_list args, char buffer[], int flags, int width, int precision, int size);
int print_octal(va_list args, char buffer[], int flags, int width, int precision, int size);
int print_hex_upper(va_list args, char buffer[], int flags, int width, int precision, int size);
int print_string_custom(va_list args, char buffer[], int flags, int width, int precision, int size);
int write_unsgnd(int is_negative, int ind, char buffer[], int flags, int width, int precision, int size);
int get_width(const char *format, int *i, va_list list);
int handle_print(const char *fmt, int *ind, va_list args, char buffer[], int flags, int width, int precision, int size);
int print_hexa(va_list args, char map_to[], char buffer[], int flags, char flag_ch, int width, int precision, int size);
int print_pointer(va_list args, char buffer[], int flags, int width, int precision, int size);
int get_size(const char *format, int *i);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);
int geet_precision(const char *format, int *i, va_list list);
int print_char(va_list args, char buffer[], int flags, int width, int precision, int size);




