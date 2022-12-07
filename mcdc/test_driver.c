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

void test_mcdc_base()
{
    mcdc1(0, 0, 0);
    mcdc1(0, 0, 1);
    mcdc1(1, 1, 0);
    mcdc1(1, 1, 1);
}

void test_mcdc_complement_1()
{
    mcdc1(0, 1, 0);
}

void test_mcdc_complement_2()
{
    mcdc1(1, 0, 0);
}

void test_mcdc_complement_3()
{
    mcdc1(0, 1, 1);
    mcdc1(1, 0, 1);
}

int main(void)
{
    test_mcdc_base();
    test_mcdc_complement_1();
    test_mcdc_complement_2();
    test_mcdc_complement_3();
#if defined LEVEL2
    test_generalized_mcdc1();
#endif
}
