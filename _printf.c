#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - prints output according to a format
 * @format: the format string to be printed
 *
 * Return: the number of characters printed (on SUCCESS),
 * or -1 if an error occured
 */

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0;

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;

            if (*format == 'S')
            {
                char *str = va_arg(args, char*);

                for (; *str != '\0'; str++)
                {
                    if (*str < ' ' || *str >= 127)
                    {
                        count += printf("\\x%02X", (unsigned char)*str);
                    }
                    else
                    {
                        putchar(*str);
                        count++;
                    }
                }
            }
        }
        else
        {
            putchar(*format);
            count++;
        }

        format++;
    }

    va_end(args);

    return count;
}
