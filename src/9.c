#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* not needed anymore
static int
is_pythagorean_triplet(int a, int b, int c)
{
    return ((pow(a, 2) + pow(b, 2)) == pow(c, 2));
}*/

static int
is_solution(int a, int b, int c)
{
     return ((pow(a, 2) + pow(b, 2)) == pow(c, 2) && (a + b + c == 1000));
}

int
main()
{
    static int a = 0;
    static int b = 0;
    static int c = 0;
    
    for (int i = 2; i <= 500; i++) {
        for (int j = 2; j <= 500; j++) {
            for (int k = 2; k <= 500; k++) {
                if (is_solution(i, j, k)) {
                    a = i;
                    b = j;
                    c = k;
                    goto end;
                }
            }
        }
    }
    
    end:
    printf("The product of the pythagorian triplet\n%d, %d, %d is %d\n", a, b, c, a * b * c);
    return EXIT_SUCCESS;   
}