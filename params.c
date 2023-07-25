#include "main.h"

/**
 * init_params - A Function To Clear Struct Fields
 * @params: The Struct of Parameter
 * @args: Arguments Pointer
*/

void init_params(params_t *params, va_list args)
{
	params->unsign = 0;
	params->plus = 0;
	params->minus = 0;

	params->zero = 0;
	params->space = 0;
	params->hashtag = 0;

	params->lng = 0;
	params->shrt = 0;

	params->width = 0;
	params->precision = UINT_MAX;

	(void)args;
}
