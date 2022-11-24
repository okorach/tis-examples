# Demo about subtle Undefined Behaviors

## Overview

This directory demonstrate how subtle Undefined Behaviors can be and why they are
most often not detected through unit tests

Spoiler: In the below tests function, there is an Undefined Behavior, you may have already spotted it...
...But that's not the point of this example. The main point is to show that due to the
Undefined Behavior, the code may behave differently depending on context.

The tested function is `increment_array()` whose implementation is below
```c
void increment_array(int *p, int len)
{
    do {
        (*p)++; // Increment the value in the array cell
        p++;    // Move to next array cell
    } while (len-- >= 0);
    return;
}
```

When testing the above with a driver like the below:
```c
int test_increment_array()
{
    int a[4] = {1, 3, 5, 7};
    char name[] = "Olivier";
    increment_array(a, ARRAY_SIZE);
    int ok = (a[0] == 2) && (a[1] == 4) && (a[2] == 6) && (a[3] == 8);
    printf("Hello %s, increment_array({1, 3, 5 ,7}) = {%d, %d, %d, %d}\n",
        name, a[0], a[1], a[2], a[3]);
    return ok;
}
```

- Unit Test will **pass**: Indeed every array cell is incremented as expected.
  This can be verified by running `make ut`
- TrustInSoft L1 (or L2) analysis will **fail**, because the above `increment_array()` function
  increments one cell to far at the end of the array.
  In the context of this test the array `a[]` (and the string `name`) are allocated in the stack, and when compiled with `gcc 9.4.0`, `a[]` and `name` are contiguous in the stack.
  The `increment_array()` function (over)writes in the `name`variable.
  This can be verified showing a little more memory information by running `make ut-debug`:
  - Before calling `increment_array()`, `name` holds the value `Olivier`
  - After  calling `increment_array()`, `name` holds the value `Plivier`

## Now the fun part: Why Undefined Behaviors are sneaky ?

It's all about context ! With an UB, the code behaves unpredictably, and differently
depending on context. Let's demonstrate that with 2 examples:
- Let's change the compiler, and use `clang` instead of `gcc`. For that run `make ut-clang`
  With that compiler, you'll notice that variables `a[]` and `name` are implanted differently in memory and because of that `name` is not overwritten (but that's pure
  luck... or unpredictability... or anything but determinism, that is, the essence of an UB)
- Let's use `gcc` again but change the value (and size) of variable `name` from
  `Olivier` to `TrustInSoft`. Because of the size change, `gcc` decides differently
  on the variable implantation in memory, and when you run the same code, the `name`
  is not overwritten (There is still an UB, just that another memory region is overwritten which is less visible from the outside).
  This can be verified by running: `make ut_long-name`

Whatever the context, the TrustInSoft Analyzer would find the Undefined Behavior
showing evidence that this is a much more reliable way of testing code for robustness
than Unit Tests.
If you have access to the TrustInSoft Analyzer this can be verified by running `make tis` or `make tis-gui`

## Conclusion

Undefined Behaviors are sometimes obvious (they can cause runtime errors like division
by zero, and software crashes) but most of the time:
- They are quite subtle
- They will materialize (cause a problem) only in certain conditions, and their
  potentially catastrophic effect may not materialize immediately (crash after some time, crash under particular circumstances, no crash but unpredictable code behavior etc...)
- Because of the above, they are quite complex to spot and investigate

The TrustInSoft analyzer solves all the above challenges by:
- Exhaustively detecting all Undefined Behaviors in the code
- Providing a powerful investigation GUI to understand the root cause of an Undefined
  Behavior and fix it quickly
  
