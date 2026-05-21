#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    for (int n = 10000; n <= 100000; n += 10000) {

        int *arr = malloc(n * sizeof(int));

        for (int i = 0; i < n; i++)
            arr[i] = rand();

        clock_t start = clock();

        bubbleSort(arr, n);

        clock_t end = clock();

        printf("Size: %d  Time: %f sec\n",
               n,
               (double)(end - start) / CLOCKS_PER_SEC);

        free(arr);
    }

    return 0;
}
