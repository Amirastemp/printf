#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * _printf - produces output according to a format
 * @format: character string containing zero or more directives
 *
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
va_list args;
int num_printed = 0;
const char *p = format;
va_start(args, format);
while (*p != '\0')
{
if (*p == '%')
{
p++;
if (*p == 'c')
{
char c = (char) va_arg(args, int);
write(1, &c, 1);
num_printed++;
}
else if (*p == 's')
{
char *s = va_arg(args, char *);
while (*s != '\0')
{
write(1, s, 1);
s++;
num_printed++;
}
}
else if (*p == '%')
{
write(1, "%", 1);
num_printed++;
}
else
{
write(1, "%", 1);
write(1, p, 1);
num_printed += 2;
}
}
else
{
write(1, p, 1);
num_printed++;
}
p++;
}
va_end(args);
return (num_printed);
}
