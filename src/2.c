#include <stdio.h>
#include <stdlib.h>

#define num 4000000

static unsigned int
fib(unsigned int n)
{
    unsigned int sum = 3, term1 = 1, term2 = 2, next = 0;
    for (int i = 1; i <= n; i++) {
        next  =  term1 + term2;
        term1 =  term2;
        term2 =  next;
        if (next % 2)
            continue;
        sum  +=  next;
    }
    return sum;
}

/*static unsigned int
fib(unsigned int n)
{
    //static unsigned int num = 0;
    return (n <= 2) ? 
    n : 
    fib(n--);
}*/

int
main()
{
    printf("The sum of all fibonacci numbers under %u is %u\n", num, fib(num));
    return EXIT_SUCCESS;
}