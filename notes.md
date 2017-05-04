# Notes
## Modulo
GCC would optimize `mod` operations to bitwise operators automatically if `-O0` or higher and the number is unsigned
> x mod 65536 is only equivalent to x & 0xffff if x is unsigned - for signed x, it gives the wrong result for negative numbers. For unsigned x, gcc does indeed optimise x % 65536 to a bitwise and with 65535 (even on -O0, in my tests).  

[source](http://stackoverflow.com/a/2661758)  
Problematic code:  
```C
static unsigned long long
fib(unsigned long long n)
{
    unsigned long long sum = 2, term1 = 1, term2 = 2, next = 0;
    for (int i = 1 ; i <= n; i++) {
        next = term1 + term2;
        #ifdef DEBUG
        printf("next: %llu\nterm1: %llu\nterm2: %llu\n\n", next, term1, term2);
        #endif
        term1 = term2;
        term2 = next;
        if (next > NUM) return sum;
        if (next % 2) continue;  // TODO: optimize
                 ^
        sum += next;
        #ifdef DEBUG
        printf("sum: %llu\n\n", sum);
        #endif
    }
    return sum;
}
```

## Using an array and addition instead of `mod 3`
Instead of 
```C
static int
get_multiples(int n)
{
    int sum = 0;
    for (int i = 0; i <= n; i++)
        if ((i % 3 == 0) || (i % 5 == 0))
            sum += i;
    return EXIT_SUCCESS;
}
```
One could use an array which size is `1000 * 5` (I think?) that stores `0` and `1` values  
If `array[value]` is `1` it means it should be included in the final sum  
This way is good because if a number is a multiple of 3 _AND_ 5 `array[number]` only needs to be checked for trueness and no other redundant operations have to be performed

## Optimizing `pow()`
According to [this](http://stackoverflow.com/a/101613) the power operation can be made more efficient (I want to try coming up with it by myself instead of copying the entire thing from Stack Overflow but I'm not that good at all that bitwise stuff)
