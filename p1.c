//p1 selection sort

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define max 20000

void selectionSort(int a[], int n);

int main(void)
{
    int a[max], n, i;
    double startTime, endTime;

    printf("Enter the number of elements to sort: ");
    scanf("%d", &n);

    // Generate random numbers
    srand(time(NULL));
    for(i = 0; i < n; i++)
        a[i] = rand()%1000;

    if(n<=25)
    {
        printf("\nBefore Sorting:\n");
        for(i = 0; i < n; i++)
            printf("%d\t", a[i]);
    }

    startTime = clock();
    selectionSort(a, n);
    endTime = clock();

    if(n<=25)
    {
        printf("\nAfter Sorting:\n");
        for(i = 0; i < n; i++)
            printf("%d\t", a[i]);
    }
    
    printf("\nTime taken is %0.2f seconds\n", (double)(endTime - startTime));

    return 0;
}

// Function to perform selection sort
void selectionSort(int a[], int n)
{
    int i, j, min, temp;
    for(i = 0; i < n-1; i++)
    {
        min = i;
        for(j = i+1; j < n; j++)
        {
            if(a[j] < a[min])
                min = j;
        }
        temp = a[min];
        a[min] = a[i];
        a[i] = temp;
    }
}
