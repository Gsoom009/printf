#include "main.h"

/**
 * get_precision - A Function To Get The Precision of Formatting String
 * @s: The Formatting String
 * @params: The Struct of Parameters
 * @args: The Pointer To Arguments
 *
 * Return: A New Pointer To Formatting String
*/

char *get_precision(char *s, params_t *params, va_list args)
{
	int wid = 0;

	if (*s != '.')
	{
		return (s);
	}

	s++;

	if (*s == '*')
	{
		wid = va_arg(args, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
		{
			wid = wid * 10 + (*s++ - '0');
		}
	}

	params->precision = wid;
	return (s);
}
