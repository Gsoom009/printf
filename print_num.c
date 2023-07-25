#include "main.h"

/**
 * _isdigit - A Function To Check if x is A Number
 * @x: The Character To Be Checked
 *
 * Return: Boolean Value
*/

int _isdigit(int x)
{
	return (x >= '0' && x <= '9');
}

/**
 * _strlen - A Function To Get The Length
 * @str: The String To Get Its Length
 *
 * Return: The Length of The String
*/

int _strlen(char *str)
{
	int i = 0;

	while (*str++)
	{
		i++;
	}

	return (i);
}

/**
 * print_number - A Function To Print A Number
 * @s: The String of Number
 * @params: The Struct of Parameters
 *
 * Return: The Printed Number
*/

int print_number(char *s, params_t params)
{
	unsigned int len = _strlen(s);
	int neg_flag = (!params->unsign && *s == '-');

	if (!params->precision && *s == '0' && !s[1])
	{
		s = "";
	}
	if (neg_flag)
	{
		s++;
		len--;
	}

	if (params->precision != UINT_MAX)
	{
		while (len++ < params->precision)
		{
			*--s = '0';
		}
	}
	if (neg_flag)
	{
		*--s = '-';
	}

	if (params->minus)
	{
		return (print_number_right_shift(s, params));
	}
	else
	{
		return (print_number_left_shift(s, params));
	}
}

/**
 * print_number_right_shift - A Function To Left Print The Number
 * @s: The String of Number
 * @params: The Struct of Parameters
 *
 * Return: The Printed Number
*/

int print_number_right_shift(char *s, params_t params)
{
	unsigned int n = 0, neg_flag_1, neg_flag_2, len = _strlen(s);
	char padding_char = ' ';

	if (params->zero && !params->minus)
		padding_char = '0';

	neg_flag_1 = neg_flag_2 = (!params->unsign && *s == '-');
	if ((neg_flag_1 && len < params->width)
		&& (padding_char == '0' && !params->minus))
		s++;
	else
		neg_flag_1 = 0;

	if ((params->plus && !neg_flag_2)
		|| (!params->plus && params->space && !neg_flag_2))
		len++;

	if (neg_flag_1 && padding_char == '0')
		n += _putchar('-');

	if (params->plus && !neg_flag_2 && padding_char == '0' && !params->unsign)
		n += _putchar('+');
	else if ((!params->plus && params->space && !neg_flag_2)
		&& (!params->unsign && params->zero))
		n += _putchar(' ');
	while (len++ < params->width)
		n += _putchar(padding_char);
	if (neg_flag_1 && padding_char == ' ')
		n += _putchar('-');
	if (params->plus && !neg_flag_2 && padding_char == ' ' && !params->unsign)
		n += _putchar('+');
	else if ((!params->plus && params->space && !neg_flag_2)
		&& (!params->unsign && !params->zero))
		n += _putchar(' ');

	n += _puts(s);
	return (n);
}

/**
 * print_number_left_shift - A Function To Left Print The Number
 * @s: The String of Number
 * @params: The Struct of Parameters
 *
 * Return: The Printed Number
*/

int print_number_left_shift(char *s, params_t params)
{
	unsigned int n = 0, neg_flag_1, neg_flag_2, len = _strlen(s);
	char padding_char = ' ';

	if (params->zero && !params->minus)
	{
		padding_char = '0';
	}
	neg_flag_1 = neg_flag_2 = (!params->unsign && *s == '-');
	if ((neg_flag_1 && len < params->width)
		&& (padding_char == '0' && !params->minus))
	{
		s++;
	}
	else
	{
		neg_flag_1 = 0;
	}
	if (params->plus && !neg_flag_2 && !params->unsign)
	{
		n += _putchar('+');
		len++;
	}
	else if (params->space && !neg_flag_2 && !params->unsign)
	{
		n += _putchar(' ');
		len++;
	}
	n += _puts(s);
	while (len++ < params->width)
	{
		n += _putchar(padding_char);
	}

	return (n);
}