#include <stdlib.h>
#include <string.h>
#include "mcdc.h"

int mcdc1(int a, int b, int c)
{

    if ((a && b) || c) {
        return 1;
    }
    else
    {
        return 0;
    }
    return 2;
}

int mcdc2(int a, int b, int c)
{

    if (c)
        return 1;
    else
    {
        if (a)
        {
            if (b)
                return 1;
            else
                return 0;
        }
        else
            return 0;
    }
    return 2;
}
