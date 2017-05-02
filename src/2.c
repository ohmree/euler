#include <stdio.h>
#include <stdlib.h>

#define num 4000000

static unsigned int
fib(unsigned int n)
{
    unsigned int sum = 0, term1 = 0, term2 = 1, next = 0;
    for (int i = 1; i <= num; i++) {
        /*if (i == 1) {
            sum += 1;
        } else if { */
            next  =  term1 + term2;
            term1 =  term2;
            term2 =  next;
            sum  +=  next;
        //}
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