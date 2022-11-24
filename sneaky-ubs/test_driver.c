#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "increment.h"

#define SUCCESS " --> PASSED"
#define FAILED  " --> *** FAILED ***"

#define ARRAY_SIZE 4
#ifdef DEBUG
#define PRINT_DEBUG printf
#else
#define PRINT_DEBUG //
#endif
int test_increment_array()
{
    int a[ARRAY_SIZE] = {1, 3, 5, 7};
#ifdef LONG_NAME
    char name[] = "TrustInSoft";
#else
    char name[] = "Olivier";
#endif
    printf("\nTest of test_increment_array()\n");
    #ifndef __TRUSTINSOFT_ANALYZER__
        PRINT_DEBUG("DEBUG: &a = 0x%lx &name = 0x%lx\n", (unsigned long)a, (unsigned long)name);
    #endif
        PRINT_DEBUG("DEBUG: Hello %s, I will be incrementing array = {%d, %d, %d, %d}\n", name, a[0], a[1], a[2], a[3]);
    increment_array(a, ARRAY_SIZE);
    PRINT_DEBUG("DEBUG: Hello %s, I have incremented array = {%d, %d, %d, %d}\n", name, a[0], a[1], a[2], a[3]);
    int ok = (a[0] == 2) && (a[1] == 4) && (a[2] == 6) && (a[3] == 8);
    printf("\nincrement_array({1, 3, 5 ,7}) = {%d, %d, %d, %d} %s\n\n",
        a[0], a[1], a[2], a[3], ok ? SUCCESS: FAILED);
    return ok;
}

int main()
{
    test_increment_array();
}
