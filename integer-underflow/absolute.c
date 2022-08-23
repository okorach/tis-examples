#include <stdlib.h>

int absolute_int(int n)
{
    int abs_n;
    if (n < 0)
        abs_n = -n;
    else
        abs_n = n;
    return abs_n;
}
