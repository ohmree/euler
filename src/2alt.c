#include <stdio.h>
#include <stdlib.h>

#define NUM 2000001

static unsigned int
fib(unsigned int n)
{
  static unsigned int term1 = 0, term2 = 1, next = 0, sum = 0;

  sum = term1 + term2;

  next = term1 + term2;

  while(next <= n)
  {

      term1 = term2;
      term2 = next;
      next = term1 + term2;
      if (next % 2)
        sum += next;
  }
  
  return sum;
}

int
main()
{
  printf("%u\n", fib(4000));
}