#include <unistd.h>

/**
 * Writes a character to the standard output (stdout).
 *
 * @param c the character to write
 * @return the number of characters written, or -1 on error
 */
int _putchar(char c) {
    return write(STDOUT_FILENO, &c, 1);
}
