#include "main.h"

/**
 * _putchar - A Fuction To Print Character
 * @c: The Character To Print
 *
 * Return: Number of Printed char
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}
