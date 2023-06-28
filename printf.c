#include"main.h"
/**
 * _printf - prints formated string 
 * @format: format string
 * Return: number of characters printed 
*/
int _printf(const char *format, ...)
{
	int i, n;
	va_list args;
	int flag;
	void (*func)(va_list*, int*);

	i = 0;
	n = 0;
	flag = 0;
	if (format == NULL)
		return (n);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && !flag)
		{
			flag = !flag;
		} else if (!flag)
		{
			_putchar(format[i]);
			n++;
		} else
		{
			func = get_specifier(format[i]);
			if (func != NULL)
			{
				func(&args, &n);
			} else
			{
				_putchar(format[i - 1]);
				_putchar(format[i]);
			}
			flag = !flag;
		}
		i++;
	}
	return (n);
}
