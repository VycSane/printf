#include <unistd.h>
/**
 * _putchar - prints a character
 * @c: the character arg
 */
void _putchar(const char c)
{
	write(1, &c, 1);
}
