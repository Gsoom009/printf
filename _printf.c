#include "main.h"

/**
 * _printf - A Function That Return Number of Printed Bytes
 *
 * @format: The Format of Printed String
 *
 * Return: Number of Printed Bytes
*/

int _printf(const char *format, ...)
{
	int sum = 0;
	char *p, *start;
	params_t params = params_Initialize;
	va_list args;

	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	for (p = (char *)format; *p; p++)
	{
		init_params(&params, args);
		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &params))
			p++;

		p = get_width(p, &params, args);
		p = get_precision(p, &params, args);
		if (get_modifier(p, &params))
			p++;

		if (!get_specifier(p))
			sum += print_from_to(start, p, params.lng || params.shrt ? p - 1 : 0);
		else
			sum += get_print_function(p, args, &params);
	}
	_putchar(Buf_Flush);
	va_end(args);

	return (sum);
}
