#ifndef PRINTF_H
#define PRINTF_H

#include<stdarg.h>
#include<unistd.h>
#include<stddef.h>

void _putchar(char);
/**
 * struct spec - specifier struct to be called by get_specifier
 * @sp: specifier character 
 * @f: pointer to a specifier function
 */
typedef struct spec
{
	char sp;
	void (*f)(va_list *list, int *n);
} spec_op;

void (*get_specifier(char s))(va_list*, int*);
void spec_c(va_list*, int*);
void spec_s(va_list*, int*);
void spec_per(va_list*, int *);
void spec_d(va_list*, int*);
void spec_i(va_list*, int*);
void spec_b(va_list*, int*);

void print_number(int, int*);
void print_binary(int, int*);

int _printf(const char *format, ...);

#endif /* PRINTF_H */
