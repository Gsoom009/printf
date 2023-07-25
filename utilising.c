#include "main.h"

/**
 * is_printable - A Function To Check If a Char Can Be Printed
 * @c: Char to be evaluated.
 *
 * Return: 1 If Printable, 0 If Not
 */

int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - A Function To Append ASCII in HEX Code
 * @buffer: Array of chars
 * @i: Index at which to start appendingS
 * @ascii_code: ASSCI CODE.
 *
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - A Function To Check For Digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - A Function To Convert A Number To Size
 * @num: Number To Be Converted
 * @size: Number Indicating The Type To Convert
 *
 * Return: The Converted Size
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - A Function To Cast A Number To The Specified Size
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: The Converted Size
 */

long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
