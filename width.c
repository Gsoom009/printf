#include "main.h"

/**
 * get_width - A Function To Calculate The Width of Argumetn
 * @format: Formatted string in which to Print The Argument
 * @i: args of arguments to be printed.
 * @args: List of Arguments
 *
 * Return: The Width of Argument
 */
int get_width(const char *format, int *i, va_list args)
{
	int curr_i;
	int width = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (width);
}