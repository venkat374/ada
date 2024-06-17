//p3 quick sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 100000

int swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return temp;
}

void quicksort(int a[], int low, int high)
{
    int s;
    if (low < high)
    {
        s = partition(a, low, high);
        quicksort(a, low, s - 1);
        quicksort(a, s + 1, high);
    }
}

int partition(int a[], int low, int high)
{
    int i, j, pivot;
    pivot = a[low];
    i = low + 1;
    j = high;
    while (1)
    {
        while ((i < high) && (pivot >= a[i]))
            i++;
        while (pivot < a[j])
            j--;
        if (i < j)
            swap(&a[i], &a[j]);
        else
        {
            swap(&a[low], &a[j]);
            return j;
        }
    }
}

void main()
{
    int a[max], n, i, low, high;
    clock_t start, end;
    float duration;
    printf("Enter number of elements to sort: ");
    scanf("%d", &n);

    if(n<= 25)
    {
        printf("Elements are: \n");
        for (i = 0; i < n; i++)
            a[i] = rand()%1000;
        printf("Before sorting: \n");
        for (i = 0; i < n; i++)
            printf("%d\t", a[i]);
        printf("\n");
    }

    start = clock();
    low = 0, high = n - 1;
    quicksort(a, low, high);
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC;
    if(n<=25)
    {
        printf("\n\nSorted array: \n");
        for (i = 0; i < n; i++)
            printf("%d\t", a[i]);
        printf("\n");
    }
    printf("\nTime taken: %0.2f\n", duration);
}
