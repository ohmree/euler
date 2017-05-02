#include <stdio.h>
#include <stdlib.h>

//#define DEBUG 
#define NUM 40000000

static unsigned long long
fib(unsigned long long n)
{
    unsigned long long sum = 2, term1 = 1, term2 = 2, next = 0;
    for (int i = 1; i <= n; i++) {
        next  =  term1 + term2;
        #ifdef DEBUG
        printf("next: %llu\nterm1: %llu\nterm2: %llu\n\n", next, term1, term2);
        #endif
        term1 =  term2;
        term2 =  next;
        if (next % 2) continue;
        sum  +=  next;
        #ifdef DEBUG
        printf("sum: %llu\n\n", sum);
        #endif
    }
    return sum;
}

/*static unsigned long long
fib(unsigned long long n)
{
    //static unsigned long long num = 0;
    return (n <= 2) ? 
    n : 
    fib(n--);
}*/

int
main()
{
    printf("The sum of all fibonacci numbers under %u is %llu\n", NUM, fib(NUM));
    return EXIT_SUCCESS;
}
