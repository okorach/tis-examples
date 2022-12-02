# Examples of Unit Tests vs TrustInSoft analysis

## Overview

This directory demonstrates the difference of purpose and results of Unit Tests vs
the TrustInSoft Analysis Level 1 then Level 2 analysis

- **Unit Tests are mostly behavioral**, they verify that the output of a function is the
expected one for some given input (and context).
- **TrustInSoft Level 1 or Level 2 analyses are mostly about robustness**. They verify that
on the path of execution of the test (L1: for discrete inputs, L2: for generalized inputs), there are no *Undefined Behaviors* (*UB*), i.e. something that may cause s*UB*tle **bugs or vulnerabilities** in some particular conditions

The examples in this directory show a certain number of cases where:
- Unit Tests all pass, but TrustInSoft analysis nevertheless detects an *UB* (a bug)
- TrustInSoft analyses all pass, but Unit Tests would detect functional problems

## First Example: Failing Unit Tests / Passing TrustInSoft Level 1 analysis 

The tested function is `increment_short()` whose very simple implementation is below:
```c
int increment_short(short i)
{
    return i + 2;
}
```
- If you unit test with any input `i` and verify that the output is `i+1`, (which is probably what the function would be supposed to do given its name) the unit test will fail.
This can be verified by running `make ut` from this directory
- If you analyze with TrustInSoft Analyzer, with any input i, the analysis will succeed because there are no *UB* in that function.
If you have access to TrustInSoft analyzer, this can be verified by running `make tis-short` from this directory

## Second Example: Passing unit tests / Failing TrustInSoft Level 1 analysis

The tested function is `increment_int()` whose very simple implementation is below
```c
int increment_int(int i)
{
    return i + 1;
}
```
- If you unit test with any input `i` and verify that the output is `i+1`, the unit test will always succeed
This can be verified by running `make ut`
- If you analyze with TrustInSoft Analyzer:
  - At **level 1** you need to test with input `INT_MAX` for the analyzer to detect the *Undefined Behavior*. (Note that this problem was not detected with UT with same input).
  If you have access to TrustInSoft analyzer, this can be verified by running `make tis-int`
  - At **level 2**, you don't need to guess what are the interesting inputs values to tests (like `INT_MAX`). The generalization system would determine the edge cases for you and raise alarms when a particular value causes an *Undefined Behavior*
  If you have access to TrustInSoft analyzer, this can be verified by running `make tis-generalized`

*Note*: If the above sounds too obvious for you, you may have a look at [Why Undefined Behaviors are sneaky ?](../sneaky-UBs/README.md)

## Conclusion

- TrustInSoft L1 + L2 analysis and Unit Tests are complementary. They don't have the same objectives.
- TrustInSoft L3 analysis is an (exhaustive) superset of Unit Tests and TrustInSoft L1 + L2. It includes all the other (above) types of tests.
