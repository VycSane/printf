#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <stdarg.h>
void _putchar(const char c);
size_t num_digits(int num);
void print_num(char buffer[], size_t *buff_pos, int num);
char get_fmt_specifier(const char *str, size_t i);
char *std_fmt(char curr_spec, va_list args);
int _printf(const char *format, ...);
void rev_string(char *s);
char *dec_base(size_t var_uint, size_t base, size_t hex_form);
char *custom_fmt(char curr_spec, va_list args);
int get_flag(char s, size_t *f);
int print_bigS(va_list l, size_t *f);
int print_rev(va_list l, size_t *f);
int print_rot13(va_list l, size_t *f);
int print_percent(va_list l, size_t *f);
#endif /* MAIN_H */
