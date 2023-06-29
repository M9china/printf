#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - prints output according to a format
 * @format: the format string to be printed
 *
 * Return: the number of characters printed (excluding the null byte used
 * to end output to strings), or -1 if an error occured
 */

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    int count = vprintf(format, args);
    va_end(args);
    return count;
}

