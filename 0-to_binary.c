#include "main.h"

void print_binary(unsigned int num) {
    unsigned int bit = 1 << (sizeof(unsigned int) * 8 - 1);
    int printed = 0;

    while (bit) {
        if (num & bit)
            putchar('1');
        else
            putchar('0');

        bit >>= 1;
        printed = 1;
    }

    if (!printed)
        putchar('0');
}

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    while (*format) {
        if (*format == '%') {
            format++;  

            if (*format == 'b') {
                unsigned int num = va_arg(args, unsigned int);
                print_binary(num);
            } else {
                putchar('%');
                putchar(*format);
            }
        } else {
            putchar(*format);
        }

        format++;
    }

    va_end(args);
    return 0;
}

int main(void) {
    _printf("%b\n", 98);
    return 0;
}

