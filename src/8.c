/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZE 14

static char* EULER_NUM = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";

static int
len(int n) {
    return (n != 0) ?
    (floor(log10(abs(n))) + 1) :
    0;
}

static char* 
take(int start, int end, char* num)
{
    static char str[SIZE];
    int i = 0, k = 0;
    for(i = start, k = 0; i < end; i++, k++) {
        if (num[i] == '\0')
            return NULL;
        str[k] = num[i];
    }
    //printf("%s\n", str);
    return str;
}

static char*
take13(int start, char* num)
{
    return take(start, start + 13, num);
}

static char*
stringify(char* arr)
{
    int length = (int) strlen(arr);
     char* str = (char*) malloc(length);
    memcpy(str, arr);
    str[++length] = '\0';
    return str;
}

static int
product_of_digits(int num)
{
    static int product = 1;
    static char str[50];
    sprintf(str, "%d", num);
    for(int i = 0; i < len(num); i++) {
        product *= (str[i] - '0');
    }
    
    return product;
}*/

int
main()
{
  //  char* meni = "hello";
   // printf("meni: %s\nstrlen(meni): %d\nstringify(meni): %s\n", meni, (int) strlen(meni), stringify(meni));
    return 0;//EXIT_SUCCESS;
}

 
 
 
 //   for (int i = 0; i <= 987; i++) {
  //      printf("%d\n", product_of_digits(atoi(take13(i, EULER_NUM))));
   // }
    //printf("%d\n", product_of_digits(12312983));
   // printf("%s\n%d\n", take13(0, EULER_NUM), product_of_digits(atoi(take13(0, EULER_NUM))));
    //int meni = atoi(take13)