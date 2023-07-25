#include "main.h"

/**
 * convert - A Function To Convert Number To Specific Number_System
 * @num: The Number To Convert
 * @base: The Base of Number_System
 * @flag: The Flag Specifier
 * @params: The Struct of Parameters
 *
 * Return: A String of The New Number
*/


char *convert(long int num, int base, int flag, params_t *params)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	(void)params;

	if (!(flag & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flag & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
	{
		*--ptr = sign;
	}

	return (ptr);
}

/**
 * print_unsigned - A Function To Print Unsigned Int Numbers
 * @args: A Pointer To Arguments
 * @params: The Struct of Parameters
 *
 * Return: The Number of Printed Bytes
*/

int print_unsigned(va_list args, params_t *params)
{
	unsigned long n;

	if (params->lng)
	{
		n = (unsigned long)va_arg(args, unsigned long);
	}
	else if (params->shrt)
	{
		n = (unsigned short int)va_arg(args, unsigned int);
	}
	else
	{
		n = (unsigned int)va_arg(args, unsigned int);
	}

	params->unsign = 1;
	return (print_number(convert(1, 10, CONVERT_UNSIGNED, params), params));
}

/**
 * print_address - A Function To Print The Address
 * @args: The Pointer To Arguments
 * @params: The Struct of Parameters
 *
 * Return: The Number of Printed Bytes
*/

int print_address(va_list args, params_t *params)
{
	char *str;
	unsigned long int n = va_arg(args, unsigned long int);

	if (!n)
	{
		return (_puts("nil"));
	}

	str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--str = 'x';
	*--str = '0';

	return (print_number(str, params));
}
