#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <stdarg.h>
void _putchar(const char c);
size_t num_digits(int num);
void print_num(char buffer[], size_t *buff_pos, int num);
char get_fmt_specifier(const char *str, size_t i);
void print_fmt(char buffer[], size_t *buff_pos, char curr_spec, va_list args);
int _printf(const char *format, ...);
#endif /* MAIN_H */
