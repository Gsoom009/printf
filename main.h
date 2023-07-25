#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define Buf_Flush -1
#define BUF_SIZE 1024
#define NULL_STRING "(null)"
#define params_Initialize {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

/**
 * struct params - Parameters Struct
 *
 * @unsign: Flag for Unsigned Value
 * @plus: Flag for Plus Parameter
 * @minus: Flag for Minus Parameter
 * @zero: Flag for Zero Value
 * @space: Flag for space
 * @hashtag: Flag for Hashtag Char
 * @lng: Flag for Long Modifier
 * @shrt: Flag for Short Modifier
 * @width: Flag For Field Width
 * @precision: Flag for Field precision
*/

typedef struct params
{
	unsigned int unsign : 1;

	unsigned int plus : 1;
	unsigned int minus : 1;

	unsigned int zero : 1;
	unsigned int space : 1;
	unsigned int hashtag : 1;

	unsigned int lng : 1;
	unsigned int shrt : 1;

	unsigned int width : 1;
	unsigned int precision : 1;
} params_t;

/**
 * struct specifier - Specifier Struct
 * @specifier: Format Specifier
 * @f: The Function of struct
*/

typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;


/* _put.c Module File*/
int _puts(char *str);
int _putchar(int c);

/* print_functions.c Module File */
int print_int(va_list args, params_t *params);
int print_char(va_list args, params_t *params);
int print_string(va_list args, params_t *params);
int print_percent(va_list args, params_t *params);
int print_S(va_list args, params_t *params);

/* number.c Module File */
char *convert(long int num, int base, int flag, params_t *params);
int print_unsigned(va_list args, params_t *params);
int print_address(va_list args, params_t *params);

/* specifier.c Module File */
int (*get_specifier(char *s))(va_list args, params_t *params);
int get_print_function(char *s, va_list args, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list args);

/* convert_number.c Module File */
int print_hex(va_list args, params_t params);
int print_HEX(va_list args, params_t params);
int print_OCTAL(va_list args, params_t params);
int print_BINARY(va_list args, params_t params);

/* simple_print.c Module File */
int print_from_to(char *start, char *stop, char *expt);
int print_reverse(va_list args, params_t *params);
int print_ROT_13(va_list args, params_t *params);

/* print_num.c Module File */
int _isdigit(int x);
int _strlen(char *str);
int print_number(char *s, params_t params);
int print_number_left_shift(char *s, params_t params);
int print_number_right_shift(char *s, params_t params);

/* params.c Module File */
void init_params(params_t *params, va_list args);

/* string_fields.c Module File */
char *get_precision(char *s, params_t *params, va_list args);

/* _printf.c Module File */
int _printf(const char *format, ...);

#endif
