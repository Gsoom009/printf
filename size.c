#include "main.h"

/**
 * get_size - A Function To Calculate The Size of Argument
 * @format: Formatted string in which to Print The Arguments
 * @i: List of arguments to be printed.
 *
 * Return: The Size of Argument
 */
int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}
