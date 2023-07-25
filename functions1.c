#include "main.h"

/**
 * print_unsigned - A Fucntion To Print A Number
 * @args: List a of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flag
 * @width: Width Specifier
 * @precision: Precision Specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_unsigned(va_list args, char buffer[],
				   int flag, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flag, width, precision, size));
}

/**
 * print_octal - A Function To Print an Number in Octal
 * @args: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flag
 * @width: Width Specifier
 * @precision: Precision Specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_octal(va_list args, char buffer[],
				int flag, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flag & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flag, width, precision, size));
}

/**
 * print_hexadecimal - A Function To Print A Number in hexadecimal
 * @args: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flag
 * @width: Width Specifier
 * @precision: Precision Specification
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */

int print_hexadecimal(va_list args, char buffer[],
					  int flag, int width, int precision, int size)
{
	return (print_hexa(args, "0123456789abcdef", buffer,
					   flag, 'x', width, precision, size));
}

/**
 * print_hexa_upper - A Function To Print a Number in Upper Hexadecimal
 * @args: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flag
 * @width: Width Specifier
 * @precision: Precision Specification
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */

int print_hexa_upper(va_list args, char buffer[],
					 int flag, int width, int precision, int size)
{
	return (print_hexa(args, "0123456789ABCDEF", buffer,
					   flag, 'X', width, precision, size));
}

/**
 * print_hexa - A Function To Print a Hex Number in Lower_Case or Upper_Case
 * @args: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flag
 * @flag_ch: Calculates active flag
 * @width: Width Specifier
 * @precision: Precision Specification
 * @size: Size specifier
 * @size: Size Specification
 *
 * Return: Number of chars printed
 */

int print_hexa(va_list args, char map_to[], char buffer[],
			   int flag, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flag & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flag, width, precision, size));
}
