#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include "main.h"
/**
 * num_digits - counts the number of digits in a number
 * @num: the number
 *
 * Return: the number of digits
 */
size_t num_digits(int num)
{
	size_t count = 0, res = 0;

	if (num == -2147483648)
	{
		res = 2147483648;
	}
	else if (num < 0)
		res = (size_t) (num * (-1));
	else
		res = num;
	while (res > 0)
	{
		count++;
		res /= 10;
	}
	return (count);
}

/**
 * print_num - prints a number
 * @buffer: the specified buffer
 * @buff_pos: the current index of the buffer
 * @num: the number
 */
void print_num(char buffer[], size_t *buff_pos, int num)
{
	size_t digit_count = num_digits(num), divisor = 1;
	size_t i, res, num_cpy;

	if (num == 0)
	{
		buffer[(*buff_pos)++] = '0';
		num_cpy = 0;
	}
	else if (num == -2147483648)
	{
		buffer[(*buff_pos)++] = '-';
		num_cpy = 2147483648;
	}
	else if (num < 0)
	{
		buffer[(*buff_pos)++] = '-';
		num_cpy = (size_t) (num * (-1));
	}
	else
	{
		num_cpy = num;
	}
	for (i = 1; i < digit_count; i++)
		divisor *= 10;
	for (i = 0; i < digit_count; i++)
	{
		res = num_cpy / divisor;
		buffer[(*buff_pos)++] = '0' + (res % 10);
		divisor /= 10;
	}
}

/**
 * get_fmt_specifier - gets the format specifier
 * @str: the string to be formatted
 * @i: the index of the specifier
 *
 * Return: the specifier
 */
char get_fmt_specifier(const char *str, size_t i)
{
	char char_to_test = str[++i];
	size_t j = 0;
	char *specs = "cs%diou";
	char *cus_specs = "b";
	size_t cus_specs_len = strlen(cus_specs);
	size_t specs_len = strlen(specs);

	for (j = 0; j < specs_len; j++)
	{
		if (char_to_test == specs[j])
			return (char_to_test);
	}
	for (j = 0; j < cus_specs_len; j++)
	{
		if (char_to_test == cus_specs[j])
			return (char_to_test);
	}
	return (0);
}

/**
 * print_fmt - prints the arg of a format type
 * @buffer: the specified buffer
 * @buff_pos: the current index of the buffer
 * @curr_spec: the current specifier being checked
 * @args: list of variable args
 */
void print_fmt(char buffer[], size_t *buff_pos, char curr_spec, va_list args)
{
	char *var_str, var_char;
	size_t len, i;
	int var_int;
	unsigned int var_uint;

	if (curr_spec == 'i')
		curr_spec = 'd';
	switch (curr_spec)
	{
		case 'c':
			var_char = va_arg(args, int);
			if (var_char == '\0')
				(*buff_pos)++;
			buffer[(*buff_pos)++] = var_char;
			break;
		case 'o':
			var_uint = va_arg(args, unsigned int);
			_oct(buffer, buff_pos, var_uint);
			break;
		case 's':
			var_str = va_arg(args, char *);
			if (var_str == NULL)
				var_str = "(null)";
			len = strlen(var_str);
			for (i = 0; i < len; i++)
				buffer[(*buff_pos)++] = var_str[i];
			break;
		case 'd':
			var_int = va_arg(args, int);
			print_num(buffer, buff_pos, var_int);
			break;
		case 'u':
			var_uint = va_arg(args, unsigned int);
			print_num(buffer, buff_pos, var_int);
		case '%':
			buffer[(*buff_pos)++] = '%';
	}
}
