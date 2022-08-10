#include "main.h"
int main(void)
{
	int num = _printf("Hello %s %b\n", "World", 2);
	_printf("%d\n", num);
	return 0;
}
