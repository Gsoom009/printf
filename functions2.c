#include "main.h"

/**
 * print_pointer - A Function To Print The Value of pointer
 * @args: List a of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flag
 * @width: Width Specifier
 * @precision: Precision Specification
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */

int print_pointer(va_list args, char buffer[],
				  int flag, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(args, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flag & F_ZERO) && !(flag & F_MINUS))
		padd = '0';
	if (flag & F_PLUS)
		extra_c = '+', length++;
	else if (flag & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, ind, length,
						  width, flag, padd, extra_c, padd_start));
}

/**
 * print_non_printable - A Function To Print ASCII Code in HEX of Some Chars
 * @args: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flag
 * @width: Width Specifier
 * @precision: Precision Specification
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */

int print_non_printable(va_list args, char buffer[],
						int flag, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(args, char *);

	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}

/**
 * print_reverse - A Function To Print A String in Reverse Order
 * @args: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flag
 * @width: Width Specifier
 * @precision: Precision Specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */

int print_reverse(va_list args, char buffer[],
				  int flag, int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(args, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

/**
 * print_rot13string - A Function To Print a string in ROT13 Decryption
 * @args: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flag
 * @width: Width Specifier
 * @precision: Precision Specification
 * @size: Size specifier
 *
 * Return: Numbers of chars printed
 */

int print_rot13string(va_list args, char buffer[],
					  int flag, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(args, char *);
	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
