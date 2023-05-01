#include <iostream>
using namespace std;

  
// A recursive function should have the following properties so that it does not result in an infinite loop:
    // 1. A simple base case (or cases) —
    // a terminating scenario that does not use recursion to produce an answer.
    
    // 2. A set of rules, also known as recurrence relation 
    // that reduces all other cases "towards" the base case.


void printReverse(const char *str) {
    // base case
    if (!*str)
        return;
    // recursive step
    printReverse(str + 1);
    // what to do
    putchar(*str);
}
