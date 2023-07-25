#include "main.h"

/**
 * get_specifier - A Function To Specify Format Function
 * @s: Formatting String
 * Return: The Number of Bytes Were Printed
*/

int (*get_specifier(char *s))(va_list args, params_t *params)
{
    specifier_t specifiers[] = {
        {"c", print_char},
        {"s", print_string},
        {"d", print_int},
        {"i", print_int},
        {"u", print_unsigned},
        {"%", print_percent},
        {"x", print_hex},
        {"X", print_HEX},
        {"o", print_OCTAL},
        {"b", print_BINARY},
        {"p", print_address},
        {"S", print_S},
        {"R", print_ROT_13},
        {"r", print_reverse},
        {NULL, NULL}
    };

    int i = 0;

    while (specifiers[i].specifier)
    {
        if (*s == specifiers[i].specifier[0])
        {
            return (specifiers[i].f);
        }
        i++;
    }

    return (NULL);
}

/**
 * get_print_function - Find The Target Formatting Function
 * @s: The Formatting String
 * @args: The Pointer To Arguments
 * @params: The Struct of Parameters
 *
 * Return: The Number of Printed Bytes or 0
*/

int get_print_function(char *s, va_list args, params_t *params)
{
    int (*f)(va_list, params_t *) = get_specifier(s);

    if (f)
    {
        return (f(args, params));
    }
    return (0);
}

/**
 * get_flag - Find The Target Flag Function
 * @s: The Formatting String
 * @params: The Struct of Parameters
 *
 * Return: A Boolean Parameter If Flag Is Valid
*/

int get_flag(char *s, params_t *params)
{
    int i = 0;

    switch (*s)
    {
        case '+':
            i = params->plus = 1;
            break;
        case '-':
            i = params->minus = 1;
            break;
        case '0':
            i = params->zero = 1;
            break;
        case ' ':
            i = params->space = 1;
            break;
        case '#':
            i = params->hashtag = 1;
            break;
    }
    return (i);
}

/**
 * get_modifier - A Function To Find Modifer Function
 * @s: The Formatting String
 * params: The Struct of Parameters
 *
 * Return: A Boolean Parameter If Flag Is Valid
*/

int get_modifier(char *s, params_t *params)
{
    int i = 0;

    switch (*s)
    {
        case 'h':
            i = params->shrt = 1;
            break;
        case 'l':
            i = params->lng = 1;
            break;
    }
    return (i);
}

/**
 * get_width - A Function To Get The Width of Formatting String
 * @s: The Formatting String
 * @params: The Struct of Parameters
 * @args: The Pointer To Arguments
 *
 * Return: A Pointer To Formatting String
*/

char *get_width(char *s, params_t *params, va_list args)
{
    int wid = 0;

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
    params->width = wid;
    return (s);
}
