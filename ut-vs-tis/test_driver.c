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
    char name[] = "Olivier";
    
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

int test_increment_short(short n)
{
    int i = increment_short(n);
    printf("increment_short(%6d) = %6d %s\n", n, i, (i != (n+1)) ? FAILED: SUCCESS);
    return ! (i == (n+1));
}

int test_increment_int(int n)
{
    int i = increment_int(n);
    printf("increment_int(%11d) = %11d %s\n", n, i, (i != (n+1)) ? FAILED: SUCCESS);
    return ! (i == (n+1));
}

int test_increment_shorts()
{
    int ok = 1;
    printf("\nTesting increment_short()\n");
    ok = test_increment_short(2) && ok;
    ok = test_increment_short(0) && ok;
    ok = test_increment_short(-1) && ok;
    ok = test_increment_short(-42) && ok;
    ok = test_increment_short(SHRT_MIN) && ok;
    ok = test_increment_short(SHRT_MAX) && ok;
    return ok;
}

int test_increment_ints()
{
    int ok = 1;
    printf("\nTesting increment_int()\n");
    ok = test_increment_int(2) && ok;
    ok = test_increment_int(0) && ok;
    ok = test_increment_int(-1) && ok;
    ok = test_increment_int(-42) && ok;
    ok = test_increment_int(INT_MIN) && ok;
    ok = test_increment_int(INT_MAX) && ok;
    return ok;
}

int main(int argc, char *argv[])
{
    int ok = 1;
    ok = test_increment_shorts() && ok;
    ok = test_increment_ints() && ok;
    ok = test_increment_array() && ok;
    // test_increment1(7);
    // test_increment1(-3);
    // test_increment1(MAGIC_VALUE);
    // test_increment1(42);
    // test_increment2(42);
    // test_increment2(-3);
    // test_increment2(MAGIC_VALUE);
    if (ok) {
        printf("All tests %s", SUCCESS);
    } else {
        printf("Some tests %s", FAILED);
    }
}
