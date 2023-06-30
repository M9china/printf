#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - prints output according to a format
 * @format: the format string to be printed
 *
 * Return: the number of characters printed (on SUCCESS),
 * or -1 if an error occured
 */

void print_rev(char *s);

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
            
            if (*format == 'r')
            {
                char *str = va_arg(args, char*);
                print_rev(str);
                int len = strlen(str);
                count += len;
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

void print_rev(char *s)
{
    int i = 0;
    
    while (s[i])
        i++;
    
    while (i--)
        putchar(s[i]);
    
    putchar('\n');
}
