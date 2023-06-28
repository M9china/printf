#include"main.h"
/**
 * print_number - prints all digits of an integer
 * @number: number to be printed
 * @n: number of character printed tracker
 * Return: nothing
 */
void print_number(int number, int *n)
{
	if (number == 0)
	{
		return;
	}
	print_number(number / 10, n);
	_putchar((number % 10) + '0');
	*n = *n + 1;
}
/**
 * print_binary - converts string to binary 
 * @number: int
 * @n: number of characters printed
 * Return: nothing
 */
void print_binary(int number, int *n)
{
	if (number == 0)
		return;
	print_binary(number / 2, n);
	_putchar((number % 2) + '0');
	*n = *n + 1;
}
