/* this one is annoying */
#include <stdio.h>

static void//unsigned int
collatz(unsigned int n)
{
    for (int i = 1; i <= n; i++) {
        printf("%d->", (i % 2)
        ? (i * 3 + 1)
        : (i / 2));
    }
    
    printf("\n");
}

int
main(void)
{
    collatz(13);
}