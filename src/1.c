/* solved */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[1001];
int sum = 0;

int
main(void)
{
    memset(arr, 0, 1001);

    for (int i = 3; i < 6; i += 2)
      for (int j = i; j < 1000; j += i)
        arr[j] = 1;

    for (int i = 0; i < 1000; i++)
      if (arr[i]) sum += i;

    printf("%d\n", sum);

    return EXIT_SUCCESS;
}
