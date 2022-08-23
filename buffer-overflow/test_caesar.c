#include <stdlib.h>
#include <stdio.h>

#include "caesar.h"

void test_caesar(char *str, int shift)
{
    char *res1, *res2;

    printf("Encrypt text '%s'\n", str);
    res1 = caesar_encrypt(str, shift);
    if (!res1) return;
    printf("Result:       %s\n", res1);

    printf("Decrypt text '%s'\n", res1);
    res2 = caesar_decrypt(res1, shift);
    if (!res2) return;
    printf("Result:       %s\n", res2);

    free(res1);
    free(res2);
}
