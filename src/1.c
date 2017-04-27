#include <stdio.h>
#include <stdlib.h>

static const int num = 999;

static int
get_multiples(int n)
{
    static int sum = 0;
    for (int i = 0; i <= n; i++)
        if ((i % 3 == 0) || (i % 5 == 0))
            sum += i;
    return sum;
}

int
main(int argc, char* argv[])
{
    int usernum = atoi(argv[1]);
    if (argc > 2) {
        printf("Usage: %s num", argv[0]);
        return EXIT_FAILURE;
    } else if (argc == 2) {
        
        printf("The sum of all the multiples of 3 or 5 below %d is %d", num, get_multiples(num));
    } else {
        printf("The sum of all the multiples of 3 or 5 below %d is %d", usernum, get_multiples(usernum));
    }
    return EXIT_SUCCESS;
}