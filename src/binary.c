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
to_binary(int num)
{
  int biggest = biggest_pow(num, 2);
  size_t len =  biggest + 1;
  char* str = malloc(sizeof(char) * (len + 1));
  str[len] = '\0';
  for (int i = 0; i < len; i++) {
    unsigned int current_value = pow(2, biggest - i);
    str[i] = (num >= current_value) + '0';
    if (num >= current_value) num -= current_value;
  }

  return str;
}

int
to_decimal(char* num, unsigned int base)
{
  len = strlen(char);
  unsigned int sum = 0;
  for (unsigned int i = 0; i <= len - 1; i++) {
    if (char[i] >= base) {
      printf("char[%d] is too big for the selected base %d", i, base);
      return -1;
    } 
    
    sum += (char[i] - '0') * pow(base, len - i);
  }
}

int
main(int argc, char* argv[])
{
  if (argc < 2) {
    printf("Usage: %s num\n", argv[0]);
    return EXIT_SUCCESS;
  }
  
  char* str = to_binary(atoi(argv[1]));
  printf("%s\n", str);
  free(str);
  return EXIT_SUCCESS;
}
