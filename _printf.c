#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Produces output according to a format 
 * @format: Character string.
 *
 * Return: number of characters printed.
 */


int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0;

    while (*format != '\0') {
        if (*format == '%') {
            format++;  

            
            switch (*format) {
                case 'c': {
                    int c = va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                }
                case 's': {
                    char *s = va_arg(args, char *);
                    while (*s != '\0') {
                        putchar(*s);
                        s++;
                        count++;
                    }
                    break;
                }
                case '%': {
                    putchar('%');
                    count++;
                    break;
                }
                default:
                    
                    break;
            }
        } else {
            putchar(*format);
            count++;
        }

        format++;
    }

    va_end(args);
    return count;
}
