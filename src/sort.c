#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* num1, int* num2)
{
    int temp = 0;
    
    temp  = *num2;
    *num2 = *num1;
    *num1 = temp;
}

int main()
{
    srand(time(NULL));
        
    int arr[10];
    
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 1001;
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    int j = 9;
    for (int i = 0; i < 9; i++)
    {
        for (int n = 0; n < j; i++) 
        {
            if (j == 1) goto end;
            if (arr[n] > arr[n+1])
                swap(&arr[n], &arr[n+1]);            
        }
        j--;
    }
    end:
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    
    printf("\n");
}