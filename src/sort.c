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

    for (int i = 0; i < 9; i++)
    {
        if (arr[i] > arr[i+1])
        {
            swap(&arr[i], &arr[i + 1]);
        }
    }
    
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    
    printf("\n");
}