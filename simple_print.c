#include "main.h"

/**
 * print_from_to - A Function To Print Char. Addresses Range
 * @start: The Starting Point Of Address
 * @stop: The Stopping Point Of Address
 * @expt: The Exception Address
 *
 * Return: The Number of Printed Bytes
*/

int print_from_to(char *start, char *stop, char *expt)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != expt)
		{
			sum += _putchar(*start);
		}
		start++;
	}
	return (sum);
}

/**
 * print_reverse - A Function To Print Character In Reverse Order
 * @args: A Pointer To Arguments
 * @params: The Struct Of Parameters
 *
 * Return: The Number of Printed Bytes
*/

int print_reverse(va_list args, params_t *params)
{
	int length, sum = 0;
	char *str = va_arg(args, char *);
	(void)params;

	if (str)
	{
		for (length = 0; *str; str++)
		{
			length++;
		}
		str--;

		for (; length > 0; length--, str--)
		{
			sum += _putchar(*str);
		}
	}
	return (sum);
}

/**
 * print_ROT_13 - A Function To Convert String in ROT13
 * @args: A Pointer To Arguments .. The String
 * @params: The Struct Of Parameters
 *
 * Return: The Number of Printed Bytes
*/

int print_ROT_13(va_list args, params_t *params)
{
	int i, idx, count = 0;
	char arr[] = "NOPQRSTUVWXYZABCDEFGHIJKLM	  nopqrstuvwxyzabcdefghijklm";
	char *str = va_arg(args, char *);
	(void)params;

	i = 0;
	idx = 0;

	while (str[i])
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
		{
			idx = str[i] - 65;
			count += _putchar(arr[idx]);
		}
		else
		{
			count += _putchar(str[i]);
		}
		i++;
	}
	return (count);
}
