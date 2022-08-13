#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include "main.h"
/**
 * custom_fmt - prints the arg of a format type
 * @buffer: the specified buffer
 * @buff_pos: the current index of the buffer      * @curr_spec: the current specifier being checked * @args: list of variable args
 */
char *custom_fmt(char curr_spec, va_list args)
{
	unsigned int var_uint;
	char *temp;

	temp = malloc(100);
	if (temp == NULL)
		exit(1);

	switch (curr_spec)
	{
		case 'b':
			var_uint = va_arg(args, unsigned int);
			temp = dec_base(var_uint, 2, 1);
			break;
		case 'X':
			var_uint = va_arg(args, unsigned int);
			temp = dec_base(var_uint, 16, 1);
	}
	return (temp);
}
