/* solved */
// TODO: optimize
// use array and addition

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 999

int arr[5005];

int
main(int argc, char* argv[])
{
    memset(arr, 0, 5005);
/*    if (argc > 2) {
        printf("Usage: %s num\n", argv[0]);
        return EXIT_FAILURE;
    } else if (argc == 1) {
        printf("The sum of all the multiples of 3 or 5 below %d is %d\n", NUM, get_multiples(NUM));
    } else {
        printf("The sum of all the multiples of 3 or 5 below %s is %d\n", argv[1], get_multiples(atoi(argv[1])));
    }*/
    printf("%d\n%d\n%d\n", arr[0], arr[500], arr[5003]);
    
    return EXIT_SUCCESS;
}

static int
get_multiples(int n)
{
    int sum = 0;
    for (int i = 0; i <= n; i++)
        /*if ((i % 3 == 0) || (i % 5 == 0))
            sum += i;*/
        arr[i] = 1;
    return EXIT_SUCCESS;
}
