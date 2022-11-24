#include <stdlib.h>
#include <stdio.h>

#ifdef __TRUSTINSOFT_ANALYZER__
#include <tis_builtin.h>
#endif

#include "mcdc.h"

#ifdef __TRUSTINSOFT_ANALYZER__
int test_generalized_mcdc1(void)
{
    long a;
    float b;
    char c;
    tis_make_unknown(&a, sizeof(a));
    tis_make_unknown(&b, sizeof(b));
    tis_make_unknown(&c, sizeof(c));
    printf("\nTest MCDC generalized\n");
    return mcdc1(a, b, c);
}
#endif

int main(void)
{
    mcdc1(0, 0, 0);
    mcdc1(0, 0, 1);
    mcdc1(1, 1, 0);
    mcdc1(1, 1, 1);

    mcdc1(0, 1, 0);
    // mcdc1(1, 0, 0);

    // mcdc1(0, 1, 1);
    // mcdc1(1, 0, 1);
    
#if defined LEVEL2
    test_generalized_mcdc1();
#endif
}
