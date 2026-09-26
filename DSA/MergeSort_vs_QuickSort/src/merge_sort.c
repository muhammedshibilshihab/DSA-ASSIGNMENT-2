/*
    Program: merge_sort.c
    Purpose: Sort fixed-length social media IDs using Merge Sort.
    Author : Muhammed Shibil Shihab (VML25CEBS016)

    This program is written in a simple, beginner-friendly style.
    It shows:
      1. The original array
      2. Every important merge step (left part, right part, merged result)
      3. The final sorted array
*/

#include <stdio.h>

#define SIZE 8

int stepCount = 0;        /* counts how many merge operations happen */
int comparisonCount = 0;  /* counts how many element comparisons happen */

/* Print an array segment from index 'start' to index 'end' (inclusive) */
void printArray(int arr[], int start, int end) {
    printf("[");
    for (int i = start; i <= end; i++) {
        printf("%d", arr[i]);
        if (i != end) {
            printf(", ");
        }
    }
    printf("]");
}

/*
   merge() combines two sorted halves:
   left half  -> arr[l .. m]
   right half -> arr[m+1 .. r]
   into a single sorted part arr[l .. r]
*/
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;   /* size of left half  */
    int n2 = r - m;       /* size of right half */

    int leftArr[n1];
    int rightArr[n2];

    /* copy data into temporary arrays */
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[m + 1 + j];
    }

    /* merge the temporary arrays back into arr[l..r] */
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        comparisonCount++;
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    /* copy any remaining elements of leftArr */
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    /* copy any remaining elements of rightArr */
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    /* ---- print this merge step ---- */
    stepCount++;
    printf("Step %d:\n", stepCount);
    printf("  Left Part    : ");
    printArray(leftArr, 0, n1 - 1);
    printf("\n");
    printf("  Right Part   : ");
    printArray(rightArr, 0, n2 - 1);
    printf("\n");
    printf("  Merged Result: ");
    printArray(arr, l, r);
    printf("\n\n");
}

/* mergeSort() splits the array into halves and calls merge() on the way back */
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);       /* sort left half  */
        mergeSort(arr, m + 1, r);   /* sort right half */

        merge(arr, l, m, r);        /* merge the two sorted halves */
    }
}

int main() {
    int arr[SIZE] = {324, 125, 456, 218, 102, 389, 275, 147};

    printf("===== Merge Sort: Social Media IDs =====\n\n");

    printf("Original Array: ");
    printArray(arr, 0, SIZE - 1);
    printf("\n\n");

    printf("---- Merge Steps ----\n\n");
    mergeSort(arr, 0, SIZE - 1);

    printf("---- Final Sorted Array ----\n");
    printArray(arr, 0, SIZE - 1);
    printf("\n\n");

    printf("Total merge operations : %d\n", stepCount);
    printf("Total comparisons made : %d\n", comparisonCount);

    return 0;
}
