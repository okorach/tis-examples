#include <stdlib.h>

#include "absolute.h"

#define MAXBUF 33

#define NB_LTR ('z' - 'a' + 1)

char *caesar_encrypt(char *str, int shift)
{
    int abs_shift = absolute_int(shift);
    int i = 0;
    char *buf = (char *)malloc(MAXBUF);

    if (buf) {
        while (*str) {
            if (*str >= 'a' && *str <= 'z')
                buf[i] = (*str + abs_shift - 'a') % NB_LTR + 'a';
            else if (*str >= 'A' && *str <= 'Z')
                buf[i] = (*str + abs_shift - 'A') % NB_LTR + 'A';
            else
                /* Spaces and other characters are not encrypted. */
                buf[i] = *str;
            i++;
            str++;
        }
        buf[i] = '\0';
    }

    return buf;
}

char *caesar_decrypt(char *str, int shift)
{
    int abs_shift = absolute_int(shift);
    int i = 0;
    char *buf = (char *)malloc(MAXBUF);

    if (buf) {
        while (*str) {
            if (*str >= 'a' && *str <= 'z')
                buf[i] = (*str + (NB_LTR - abs_shift) - 'a') % NB_LTR + 'a';
            else if (*str >= 'A' && *str <= 'Z')
                buf[i] = (*str + (NB_LTR - abs_shift) - 'A') % NB_LTR + 'A';
            else
                /* Spaces and other characters are not encrypted. */
                buf[i] = *str;
            i++;
            str++;
        }
        buf[i] = '\0';
    }
    return buf;
}
