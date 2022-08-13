#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include "main.h"
#include <stdio.h>
/**
 * dec_base - converts a decimal number to a specified base
 * @var_uint: the number
 * @base: base to convert to
 * @hex_form: how to format hex letters
 *
 * Return: the new base as string
 */
char *dec_base(size_t var_uint, size_t base, size_t hex_form)
{
	char *temp, tmp;
	size_t rem, i = 0, j = 0;

	temp = malloc(100);
	if (temp == NULL)
		exit(1);
	if (var_uint == 0)
		temp[i++] = '0';
	while (var_uint > 0)
	{
		rem = var_uint % base;
		var_uint /= base;
		if (rem > 9 && hex_form == 1)
			temp[i++] = 65 + rem - 10;
		if (rem > 9 && hex_form == 2)
			temp[i++] = 97 + rem - 10;
		else
			temp[i++] = '0' + rem;
	}
	temp[i] = '\0';
	rev_string(temp);
	return (temp);
}
