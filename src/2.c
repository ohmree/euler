/* solved */
#include <stdio.h>
#include <stdlib.h>

//#define DEBUG    0000000
#define NUM 4000000

static unsigned long long
fib(unsigned long long n)
{
    unsigned long long sum = 2, term1 = 1, term2 = 2, next = 0;
    for (int i = 1 ; i <= n; i++) {
        next = term1 + term2;
        #ifdef DEBUG
        printf("next: %llu\nterm1: %llu\nterm2: %llu\n\n", next, term1, term2);
        #endif
        term1 = term2;
        term2 = next;
        if (next > NUM) return sum;
        if (next & 1) continue;  // This works because fib() is unsigned
        sum += next;
        #ifdef DEBUG
        printf("sum: %llu\n\n", sum);
        #endif
    }
    return sum;
}

int
main(void)
{
    printf("The sum of all fibonacci numbers whose value is under %u is %llu\n", NUM, fib(NUM));
    return EXIT_SUCCESS;
}
