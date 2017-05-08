#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define NUM 1000000

static bool*
sieve_of_erastothenes(unsigned long long max)
{
  bool* arr = /* (bool*) */ malloc(max * (sizeof(bool)) + 1);
  if ( !arr ) return NULL;
  memset(arr, true, max);
  arr[0] = arr[1] = 0;

  for (unsigned long long i = 2; i < max; ++i) {
    if (!arr[i]) continue;
    for (unsigned long long j = i + i; j < max; j += i)
      arr[j] = false;
  }

  return arr;
}


static unsigned long
nth_prime(unsigned long n)
{
  unsigned long num = 0;
  unsigned int count = 0;
  bool* arr = sieve_of_erastothenes(NUM);

  for (int i = 0; count < n; i++)
    //printf("i: %d\narr[i]: %d\nnum:%ld\n\n", i, arr[i], num);
    if (arr[i]) {
      num = i;
      count++;
    }
  printf("count: %d\n", count);

  free(arr);
  return num;
}

int
main(void)
{
  printf("%lu\n", nth_prime(10001));
  return EXIT_SUCCESS;
}
