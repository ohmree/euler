#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

//#define NUM 54
/*
bool
naive_prime(unsigned long long num)
{
  for (unsigned int i = 2; i <= num/2; i++)
    if (!(num % i)) return false;
  return true;
}
*/

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

static long
nth_prime(unsigned long num)
{
  int square = sqrt(num);
  bool* arr = sieve_of_erastothenes(square);
  for (int i = square; i >= 0; --i) {
    if (arr[i] && !(num % i)) return i;
  }
  return -1;
  free(arr);
}

int
main(void)
{
  //bool *arr = sieve_of_erastothenes(1000);
  printf("%ld\n", nth_prime(600851475143));

  //for (int i = 0; i <= 1000; i++) printf("%d ", arr[i]);
  //printf("\n");
  //free(arr);
  return 0;
}

/*  LocalWords:  NUM bool num LocalWords erastothenes
 */
