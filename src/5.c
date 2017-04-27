#include <stdio.h>
#include <stdlib.h>

#define DEBUG 1

static unsigned int
smallest_evenly_divisible_until(unsigned int n)
{
    static unsigned int smallest = 0;
    start:
    for (unsigned int num = 1;; num++) {
        for (unsigned int i = 1; i <= n; i++) {
            if (!(num % i) && i < n) {
                if (DEBUG) printf("num = %u\ni = %u\nsmallest = %u\n", num, i, smallest);
                continue;
            } else if (!(num % i) && i == n) {
                if (DEBUG) printf("num = %u\ni = %u\nsmallest = %u\n", num, i, smallest);
                smallest = num;
            } else {
                if (DEBUG) printf("num = %u\ni = %u\nsmallest = %u\n", num, i, smallest);
                goto start;
            }
        }
    }
    return smallest;
}

int
main()
{
    printf("Ayy %u\n", smallest_evenly_divisible_until(20));
    return EXIT_SUCCESS;   
}