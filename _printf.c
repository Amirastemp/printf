#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;

    while (*format != '\0') {
        if (*format == '%') {
            format++;
            if (*format == 'c') {
                char c = va_arg(args, int);
                fwrite(&c, sizeof(char), 1, stdout);
                count++;
            } else if (*format == 's') {
                char *s = va_arg(args, char *);
                fwrite(s, sizeof(char), strlen(s), stdout);
                count += strlen(s);
            } else if (*format == '%') {
                fwrite("%", sizeof(char), 1, stdout);
                count++;
            }
        } else {
            fwrite(format, sizeof(char), 1, stdout);
            count++;
        }
        format++;
    }

    va_end(args);

    return count;
}
