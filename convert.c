#include "main.h"

/**
 * checker - Function to check for format specifiers
 * @format: Pointer to string
 * @symbols: Array of format structure
 * @str: Pointer to args
 * Return: Number of characters printed
 */
int checker(const char *format, format_t symbols[], va_list str)
{
	int i = 0;
	int printed_chars = 0;

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] != '\0')
			{
				int j = 0;
				while (symbols[j].sign != NULL)
				{
					if (format[i + 1] == symbols[j].sign[0])
					{
						if (format[i + 1] == 'd' || format[i + 1] == 'i')
						{
							int value = va_arg(str, int);
							printed_chars += _putint(value);
						}
						else
						{
							int outcome = symbols[j].fun(str);
							if (outcome == -1)
								return -1;
							printed_chars += outcome;
						}
						break;
					}
					j++;
				}
				if (symbols[j].sign == NULL && format[i + 1] != ' ')
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					printed_chars += 2;
				}
				i++;
			}
			else
				return -1;
		}
		else
		{
			_putchar(format[i]);
			printed_chars++;
		}
		i++;
	}

	return printed_chars;
}

