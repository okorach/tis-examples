#include <stdlib.h>
#include <stdio.h>

#include "absolute.h"

void test_absolute_int(int val)
{
    printf("abs(%d) = %d\n", val, absolute_int(val));
}
