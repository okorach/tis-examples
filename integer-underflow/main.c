#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "test_absolute.h"

int main(void)
{
    test_absolute_int(10);
    test_absolute_int(0);
    test_absolute_int(-1);
    test_absolute_int(-65536);
    test_absolute_int(INT_MIN);
    test_absolute_int(INT_MAX);
    return 0;
}
