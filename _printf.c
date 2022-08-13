#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"
#define STDOUT 1
/**
 * _printf - prints a formatted string
 * @format: the string to be formatted
 * @...: the variable list of args
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	char buffer[2024];
	size_t buff_pos = 0;
	size_t i, fmt_strlen;
	char c, curr_spec;
	int buff_strlen = 0;
	va_list args;

	if (format == NULL)
		exit(98);
	fmt_strlen = strlen(format);
	va_start(args, format);
	for (i = 0; i < fmt_strlen; i++)
	{
		c = format[i];
		if (c != '%')
		{
			buffer[buff_pos++] = c;
		}
		else if (c == '%')
		{
			curr_spec = get_fmt_specifier(format, i);
			if (!curr_spec)
			{
				buffer[buff_pos++] = c;
				continue;
			}
			i++;
			print_fmt(buffer, &buff_pos, curr_spec, args);
			custom_fmt(buffer, &buff_pos, curr_spec, args);
		}
	}
	buffer[buff_pos] = '\0';
	buff_strlen = (int) strlen(buffer);
	write(STDOUT, buffer, buff_strlen);
	va_end(args);
	return (buff_strlen);
}
