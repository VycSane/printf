#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"
#include <stdio.h>
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
	size_t buff_pos = 0, i, j = 0, fmt_strlen;
	char *buffer, *tmp_buff, c, curr_spec;
	size_t buff_strlen = 0;
	va_list args;

	if (format == NULL)
		exit(98);
	fmt_strlen = strlen(format);
	buffer = malloc(2024);
	if (buffer == NULL)
		exit(99);
	va_start(args, format);
	for (i = 0; i < fmt_strlen; i++)
	{
		c = format[i];
		if (c != '%')
		{
			buffer[buff_pos++] = c;
		}
		else if (c == '%' && format[i + 1] == '\0')
		{
			return (-1);
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
			tmp_buff = std_fmt(curr_spec, args);
			for (j = 0; tmp_buff[j] != '\0'; j++)
				buffer[buff_pos++] = tmp_buff[j];
			free(tmp_buff);
			tmp_buff = custom_fmt(curr_spec, args);
			for (j = 0; tmp_buff[j] != '\0'; j++)
				buffer[buff_pos++] = tmp_buff[j];
			free(tmp_buff);
		}
	}
	buff_strlen = strlen(buffer);
	write(STDOUT, buffer, buff_strlen);
	free(buffer);
	va_end(args);
	return (buff_strlen);
}
