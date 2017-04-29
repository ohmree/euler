#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static unsigned int
sum_of_squares(unsigned int n) {
    static int the_sum = 0;
    for (int i = 0; i <= n; i++)
        the_sum += pow(i, 2);

    return the_sum;
}

static unsigned int
square_of_sum(unsigned int n) {
    static int the_sum = 0;
    for (int i = 0; i <= n; i++)
        the_sum += i;
    
    return pow(the_sum, 2);
}

int
main()
{
    
    printf("The answer is %u\n", (square_of_sum(100) - sum_of_squares(100)));
    return EXIT_SUCCESS;
}