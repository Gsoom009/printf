#include "main.h"

/**
 * print_hex - A Function To Print HEX Numbers
 * @args: The Pointer To Arguments
 * @params: The Struct of Parameters
 *
 * Return: The Number of Printed Bytes
*/


int print_hex(va_list args, params_t params)
{
	unsigned long n;
	int c = 0;
	char *str;

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

	str = convert(1, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);

	if (params->hashtag && n)
	{
		*--str = 'x';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += print_number(str, params));
}

/**
 * print_HEX - A Function To Print HEX Numbers
 * @args: The Pointer To Arguments
 * @params: The Struct of Parameters
 *
 * Return: The Number of Printed Bytes
*/


int print_HEX(va_list args, params_t params)
{
	unsigned long n;
	int c = 0;
	char *str;

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

	str = convert(1, 16, CONVERT_UNSIGNED, params);

	if (params->hashtag && n)
	{
		*--str = 'X';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += print_number(str, params));
}

/**
 * print_BINARY - A Function To Print Binary Numbers
 * @args: The Pointer To Arguments
 * @params: The Struct of Parameters
 *
 * Return: The Number of Printed Bytes
*/


int print_BINARY(va_list args, params_t params)
{
	unsigned int n = va_arg(args, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, params);
	int c = 0;

	if (params->hashtag && n)
	{
		*--str = '0';
	}
	params->unsign = 1;
	return (c += print_number(str, params));
}

/**
 * print_OCTAL - A Function To Print Octal Numbers
 * @args: The Pointer To Arguments
 * @params: The Struct of Parameters
 *
 * Return: The Number of Printed Bytes
*/

int print_OCTAL(va_list args, params_t params)
{
	unsigned long n;
	char *str;
	int c = 0;

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

	str = convert(n, 8, CONVERT_UNSIGNED, params);

	if (params->hashtag && n)
	{
		*--str = '0';
	}
	params->unsign = 1;

	return (c += print_number(str, params));
}
