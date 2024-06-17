//p2 merge sort

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define max 10000

void simple_merge(int a[], int low, int mid, int high);
void merge_sort(int a[], int low, int high);

int main(void)
{
    int a[max], n, i = 0;
    clock_t startTime, endTime;

    printf("Enter the number of elements to sort: ");
    scanf("%d", &n);

    // Generate random elements
    for (i = 0; i < n; i++)
        a[i] = rand()%1000;
    if(n<=25)
    {
        printf("Before sorting:\n");
        for (i = 0; i < n; i++)
            printf("%d\t", a[i]);
    }

    startTime = clock();
    merge_sort(a, 0, n - 1);
    endTime = clock();

    if(n<=25)
    {
        printf("\n\nAfter sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
    }

    printf("\nTime taken is %0.2f seconds\n", (double)(endTime - startTime)/CLOCKS_PER_SEC);

    return 0;
}

void simple_merge(int a[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = low, c[max];

    while (i <= mid && j <= high) {
        if (a[i] < a[j]) {
            c[k] = a[i];
            i++;
        } else {
            c[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
        c[k++] = a[i++];

    while (j <= high)
        c[k++] = a[j++];

    for (i = low; i <= high; i++)
        a[i] = c[i];
}

void merge_sort(int a[], int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        merge_sort(a, low, mid);
        merge_sort(a, mid + 1, high);
        simple_merge(a, low, mid, high);
    }
}