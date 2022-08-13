#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include "main.h"
/**
 * custom_fmt - prints the arg of a format type
 * @buffer: the specified buffer
 * @buff_pos: the current index of the buffer
 * @curr_spec: the current specifier being checked
 * @args: list of variable args
 */
void custom_fmt(char buffer[], size_t *buff_pos, char curr_spec, va_list args)
{
	unsigned int var_uint;

	switch (curr_spec)
	{
		case 'b':
			var_uint = va_arg(args, unsigned int);
			print_binary(buffer, buff_pos, var_uint);
			break;
	}
}
