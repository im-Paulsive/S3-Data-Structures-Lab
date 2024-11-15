#include <stdio.h>
#include <stdlib.h>

int a[100];
int b[100];

void merge(int a[], int lb, int mid, int ub);
void mergesort(int a[], int lb, int ub);

void mergesort(int a[], int lb, int ub) {
    int mid;
    if (lb < ub) {
        mid = (lb + ub) / 2;
        mergesort(a, lb, mid);     // Left half
        mergesort(a, mid + 1, ub); // Right half
        merge(a, lb, mid, ub);     // Merge both halves
    }
}

void merge(int a[], int lb, int mid, int ub) {
    int i = lb;
    int j = mid + 1;
    int k = lb;

    while (i <= mid && j <= ub) {
        if (a[i] <= a[j]) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of left subarray
    while (i <= mid) {
        b[k] = a[i];
        i++;
        k++;
    }

    // Copy remaining elements of right subarray
    while (j <= ub) {
        b[k] = a[j];
        j++;
        k++;
    }

    // Copy sorted subarray from b[] back to a[]
    for (i = lb; i <= ub; i++) {
        a[i] = b[i];
    }
}

int main() {
    int i, n;
    printf("Enter limit: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    mergesort(a, 0, n - 1);

    printf("Sorted array is: \n");
    for (i = 0; i < n; ++i) {
        printf("%d\n", a[i]);
    }

    return 0;
}
