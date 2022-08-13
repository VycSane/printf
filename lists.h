#ifndef LISTS_H
#define LISTS_H
#include <stddef.h>
#include <stdarg.h>
void _putchar(const char c);
size_t num_digits(int num);
void print_num(char buffer[], size_t *buff_pos, int num);
char get_fmt_specifier(const char *str, size_t i);
void print_fmt(char buffer[], size_t *buff_pos, char curr_spec, va_list args);
int _printf(const char *format, ...);
void rev_string(char *s);
void print_binary(char buffer[], size_t *buff_pos, unsigned int var_uint);
void custom_fmt(char buffer[], size_t *buff_pos, char curr_spec, va_list args);
void _oct(char buffer[], size_t *buff_pos, unsigned int var_uint);
int get_flag(char s, size_t *f);
int print_bigS(va_list l, size_t *f);
int print_rev(va_list l, size_t *f);
int print_rot13(va_list l, size_t *f);
int print_percent(va_list l, size_t *f);
#endif /* LISTS_H */
