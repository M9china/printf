#include"main.h"
/**
 * spec_b - converts unsigned int to binary
 * @args: variable list
 * @n: pointer to variable
 * Return: nothing
 */
void spec_b(va_list *args, int *n)
{
	int number;

	number = va_arg(*args, int);
	if (number == 0)
	{
		_putchar('0');
		return;
	}
	if (number < 0)
		number = number * (-1);
	print_binary(number, n);
}
