#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include "lists.h"
/**
 * _hex - converts decimal to hexadecimal
 * @buffer: the buffer arg
 * @buff_pos: the buffer current index
 * @var_uint: the number
 */
void _hex(char buffer[], size_t *buff_pos, unsigned int var_uint);
/**
 * _oct - converys decimal to octal
 * @buffer: the buffer arg
 * @buff_pos: the buffer current index
 * @var_uint: the number
 */
void _oct(char buffer[], size_t *buff_pos, unsigned int var_uint)
{
	char temp[100];
	int rem, i = 0, j = 0;

	if (var_uint == 0)
		buffer[(*buff_pos)++] = '0';
	while (var_uint > 0)
	{
		rem = var_uint % 8;
		var_uint /= 8;
		temp[i++] = '0' + rem;
		j++;
	}
	temp[i] = '\0';
	while (j > 0)
	{
		buffer[(*buff_pos)++] = temp[j - 1];
		j--;
	}
}
/**
 * print_binary - prints a decimal number in binary format
 * @buffer: the buffer arg
 * @buff_pos: the buffer current index
 * @var_uint: the number
 */
void print_binary(char buffer[], size_t *buff_pos, unsigned int var_uint)
{
	char temp[100];
	int rem, i = 0, j = 0;

	if (var_uint == 0)
		buffer[(*buff_pos)++] = '0';
	while (var_uint > 0)
	{
		rem = var_uint % 2;
		var_uint /= 2;
		temp[i++] = '0' + rem;
		j++;
	}
	temp[i] = '\0';
	while (j > 0)
	{
		buffer[(*buff_pos)++] = temp[j - 1];
		j--;
	}
}
