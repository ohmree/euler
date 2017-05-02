#include <stdio.h>
#include <stdlib.h>

#define num 4000000

static unsigned int
fib(unsigned int n)
{
    unsigned int sum = 0, term1 = 0, term2 = 1, next = 0;
    for (int i = 1; i <= n; i++) {
        if (i < 2) {
            sum = i;
        } else {
            next  =  term1 + term2;
            term1 =  term2;
            term2 =  next;
            sum  +=  next;
        }
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