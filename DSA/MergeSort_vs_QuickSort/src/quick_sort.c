/*
    Program: quick_sort.c
    Purpose: Sort fixed-length social media IDs using Quick Sort.
    Author : Muhammed Shibil Shihab (VML25CEBS016)

    This program uses the Lomuto partition scheme (last element as pivot),
    written in a simple, beginner-friendly style. It shows:
      1. Every important partition step (pivot, array after partition)
      2. The final sorted array
*/

#include <stdio.h>

#define SIZE 8

int partitionCount = 0;   /* counts how many partition operations happen */
int comparisonCount = 0;  /* counts how many pivot comparisons happen */

/* Print the whole array */
void printArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i != size - 1) {
            printf(", ");
        }
    }
    printf("]");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
   partition() picks the last element (arr[high]) as the pivot,
   places it in its correct sorted position, and puts all smaller
   elements before it and all larger elements after it.
   Returns the final index of the pivot.
*/
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;   /* index of the last element smaller than pivot */

    partitionCount++;
    printf("Partition %d:\n", partitionCount);
    printf("  Pivot         : %d\n", pivot);
    printf("  Comparisons   :\n");

    for (int j = low; j < high; j++) {
        comparisonCount++;
        if (arr[j] <= pivot) {
            printf("    %d <= %d -> smaller, move to left side\n", arr[j], pivot);
            i++;
            swap(&arr[i], &arr[j]);
        } else {
            printf("    %d > %d  -> stays on right side\n", arr[j], pivot);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    int pivotIndex = i + 1;

    printf("  Result Array  : ");
    printArray(arr, SIZE);
    printf(" (pivot %d placed at index %d)\n\n", pivot, pivotIndex);

    return pivotIndex;
}

/* quickSort() recursively sorts arr[low..high] */
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);   /* sort left part  */
        quickSort(arr, pivotIndex + 1, high);  /* sort right part */
    }
}

int main() {
    int arr[SIZE] = {324, 125, 456, 218, 102, 389, 275, 147};

    printf("===== Quick Sort: Social Media IDs =====\n\n");

    printf("Original Array: ");
    printArray(arr, SIZE);
    printf("\n\n");

    printf("---- Partition Steps ----\n\n");
    quickSort(arr, 0, SIZE - 1);

    printf("---- Final Sorted Array ----\n");
    printArray(arr, SIZE);
    printf("\n\n");

    printf("Total partition operations : %d\n", partitionCount);
    printf("Total comparisons made      : %d\n", comparisonCount);

    return 0;
}
