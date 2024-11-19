#include <stdio.h>
#include <unistd.h>
#include <string.h>

int puts(const char *str) {
    size_t length = strlen(str);
    ssize_t written = write(1, str, length);

    if (written < 0)
        return -1;
    char newl = '\n';
    if (write(1, &newl, 1) < 0)
        return -1;
    return written + 1;
}
