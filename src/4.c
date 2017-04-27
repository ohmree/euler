#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//#include <math.h>

#define SIZE 50

/* Would it be more correct to check the length
   of the palindrome and discard single number results?*/
/*static int
len(int n) {
    return (n != 0) ?
    (floor(log10(abs(n))) + 1) :
    0;
}*/

/**
  * Find if a number is a palindrome by
  * converting it to a string and comparing
  * it against an inverted version of that string
  */
static int 
palindrome_number(unsigned int n, unsigned int m)
{
    int i, k = 0;
    char str1[SIZE], str2[SIZE];
    
    sprintf(str1, "%d", (n * m));
    for (i = (strlen(str1) - 1), k = 0; i >= 0 && k <= (strlen(str2)); i--, k++) {
        str2[k] = str1[i];
    }
    return (atoi(str1) == atoi(str2))
    ? atoi(str1)
    : 0;
}

/** 
  * Iterate over all possible 3 digit pairs and
  * check if their multiple is a palindrome,
  * storing the largest result and printing it
  */ 
int
main()
{
    int i = 0, k = 0, largest = palindrome_number(2, 2);
    for (i = 2; i <= 999; i++) {
        for (k = 2; k <= 999; k++) {
            int num = palindrome_number(i, k);
            if (num != 0 && num >= largest) {
                largest = num;
            } else {
                continue;
            }
        }
    }
    printf("The answer is %d\n", largest);
    return EXIT_SUCCESS;
}