#include "main.h"

/**
 * print_char - A Function To Print Characters
 * @args: A Pointer To Arguments
 * @params: The Struct of Parameters
 *
 * Return: The Number of Printed Bytes
*/

int print_char(va_list args, params_t *params)
{
	char padding_char = ' ';
	unsigned int pad = 1, sum = 0, c = va_arg(args, int);

	if (params->minus)
	{
		sum += _putchar(c);
	}

	while (pad++ < params->width)
	{
		sum += _putchar(padding_char);
	}

	if (params->minus)
	{
		sum += _putchar(c);
	}
	return (sum);
}

/**
 * print_int - A Function To Print Integer
 * @args: A Pointer To Arguments
 * @params: The Struct of Parameters
 *
 * Return: The Number of Printed Bytes
*/

int print_int(va_list args, params_t *params)
{
	long n;

	if (params->lng)
	{
		n = va_arg(args, long);
	}
	else if (params->shrt)
	{
		n = (short int)va_arg(args, int);
	}
	else
	{
		n = (int)va_arg(args, int);
	}

	return (print_number(convert(1, 10, 0, params), params));
}

/**
 * print_string - A Function To Print String
 * @args: A Pointer To Arguments
 * @params: The Struct of Parameters
 *
 * Return: The Number of Printed Bytes
*/

int print_string(va_list args, params_t *params)
{
	char *str = va_arg(args, char *), padding_char = ' ';
	unsigned int pad = 0, sum = 0, i = 0, j = 0;
	(void)params;

	switch ((int)(!str))
		case 1:
			str = NULL_STRING;

	j = pad = _strlen(str);
	if (params->precision < pad)
		j = pad = params->precision;

	if (params->minus)
	{
		if (params->precision != UINT_MAX)
		{
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		}
		else
			sum += _puts(str);
	}

	while (j++ < params->width)
		sum += _putchar(padding_char);

	if (!params->minus)
	{
		if (params->precision != UINT_MAX)
		{
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		}
		else
			sum += _puts(str);
	}
	return (sum);
}

/**
 * print_percent - A Function To Print Percentage Character
 * @args: A Pointer To Arguments
 * @params: The Struct of Parameters
 *
 * Return: The Number of Printed Bytes
*/

int print_percent(va_list args, params_t *params)
{
	(void)params;
	(void)args;

	return (_putchar('%'));
}

/**
 * print_S - A Function To Print String Address in HEX
 * @args: A Pointer To Arguments
 * @params: The Struct of Parameters
 *
 * Return: The Number of Printed Bytes
*/

int print_S(va_list args, params_t *params)
{
	int sum = 0;
	char *hex_str;
	char *str = va_arg(args, char *);

	if ((int)(!str))
	{
		return (_puts(NULL_STRING));
	}

	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex_str = convert(*str, 16, 0, params);

			if (!hex_str[1])
			{
				sum += _putchar('0');
			}
			sum += _puts(hex_str);
		}
		else
		{
			sum += _putchar(*str);
		}
	}

	return (sum);
}
