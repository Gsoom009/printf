#include "main.h"

/**
 * _printf - A Function Similar TO printf in C
 * @format: The Format of The String To Print
 * @...: The Arguments To Print
 *
 * Return: The Number of Printed Bytes
*/

int _printf(const char *format, ...)
{
	unsigned int idx = 0, sum = 0;
	va_list args;

	va_start(args, format);

	for (; format[idx] != '\0'; idx++)
	{
		if (format[idx] != '%')
		{
			_putchar(format[idx]);
		}
		else if (format[idx + 1] == 'c')
		{
			_putchar(va_arg(args, int));
			idx++;
		}
		sum += 1;
	}
	return (sum);
}
