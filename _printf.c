#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
    int count = 0;

    va_list args;
    va_start(args, format);

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
                case 'd':
                case 'i': {
                    int num = va_arg(args, int);
                    printf("%d", num);
                    int printed_chars = snprintf(NULL, 0, "%d", num);
                    count += printed_chars;
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

