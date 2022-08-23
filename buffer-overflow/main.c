#include <stdlib.h>
#include <stdio.h>

#include "test_caesar.h"

int main(void)
{

    char orig_str[] = "People of Earth, your attention please";

    printf("Test 1: Shift with a negative input\n");
    test_caesar(orig_str, -3);
    printf("\nTest 2: Shift with a positive input\n");
    test_caesar(orig_str, 7);

    return 0;
}
