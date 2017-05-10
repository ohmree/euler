#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int
biggest_pow(int num, int base)
{
  int i = 0;

  for (i = 1 ; pow(base, i) <= num; i++);
  return i - 1;
}

char*
decimal_to_base(int num, int base)
{
  int biggest = biggest_pow(num, base);
  size_t len =  biggest + 1;
  char* str = malloc(sizeof(char) * (len + 1));
  str[len] = '\0';
  for (int i = 0; i < len; i++) {
    unsigned int current_value = pow(base, biggest - i);
    str[i] = (num >= current_value) + '0';
    if (num >= current_value) num -= current_value;
  }

  return str;
}

int
to_decimal(char* num, unsigned int base)
{
  unsigned int len = strlen(num);
  unsigned int sum = 0;
  for (unsigned int i = 0; i <= len - 1; i++) {
    if (num[i] >= base) {
      printf("char[%d] is too big for the selected base %d", i, base);
      return -1;
    } 
    
    sum += (num[i] - '0') * pow(base, len - i);
  }
  
  return sum;
}

int
main(int argc, char* argv[])
{
  if (argc < 4) {
    printf("Usage: %s from to num\n", argv[0]);
    return EXIT_SUCCESS;
  }
  
  int from = atoi(argv[1]), to = atoi(argv[2]), num = atoi(argv[3]);
  
  char* str = decimal_to_base(num, from);
  printf("%s\n", str);
  
  free(str);
  return EXIT_SUCCESS;
}
