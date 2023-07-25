#include "main.h"

void print_buffer(char buffer[], int *buff_idx);

/**
 * _printf - A Function Similar To Printf function
 * @format: The Specified Format
 * Return: The Number of Printed Bytes
*/
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_idx = 0;
	va_list args;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_idx++] = format[i];
			if (buff_idx == BUFF_SIZE)
				print_buffer(buffer, &buff_idx);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_idx);
			flags = get_flags(format, &i);
			width = get_width(format, &i, args);
			precision = get_precision(format, &i, args);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, args, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_idx);

	va_end(args);

	return (printed_chars);
}

/**
 * print_buffer - A Function To Print The Content of The Buffer
 * @buffer: An Array of Characters
 * @buff_idx: The Index To Add A Char At
*/
void print_buffer(char buffer[], int *buff_idx)
{
	if (*buff_idx > 0)
		write(1, &buffer[0], *buff_idx);

	*buff_idx = 0;
}
