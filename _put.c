#include "main.h"

/**
 * _puts - Function To Print String Followed By New Line
 * @str: The String We Need To Print
 * Return: Void
*/

int _puts(char *str)
{
	char *a = str;

	while (*str)
	_putchar(*str++);

	return (str - a);
}

/**
 * _putchar - A Function To Print Each Character
 * @c: The Character We Need To Print
 * Return: 0 in case of success or 1 in case of failure
*/

int _putchar(int c)
{
	static int i;
	static char buf[BUF_SIZE];

	if (c == Buf_Flush || i >= BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}

	if (c != Buf_Flush)
	{
		buf[i++] = c;
	}

	return (1);
}
