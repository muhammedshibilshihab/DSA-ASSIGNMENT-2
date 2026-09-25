# Algorithm Analysis Report: Fixed-Length IDs

**Student Details:**
* **Name:** Muhammed Shibil Shihab
* **Department:** Computer Science and Engineering with Business Systems (CEBS)
* **Roll No:** VML25CEBS016

---

## Problem Statement
A social media application needs to sort the following fixed-length user identification numbers (IDs):

`324, 125, 456, 218, 102, 389, 275, 147`

---

## Part A: Merge Sort Implementation & Execution

> **Technical Note:** Merge Sort is a comparison-based divide-and-conquer algorithm that operates through recursive array bisection and merging (unlike Radix Sort, which processes individual digit positions). The trace table below records the exact state of the array after each **merge pass/step**.

### C Code Implementation (Abbreviated)

```c
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
```

### Execution Trace Table

| Pass | Subarrays Merged | Array State After Pass |
| :--- | :--- | :--- |
| **Initial** | — | `324, 125, 456, 218, 102, 389, 275, 147` |
| **Pass 1** *(Size 1 → 2)* | `[324]` & `[125]`, `[456]` & `[218]`, `[102]` & `[389]`, `[275]` & `[147]` | `125, 324, 218, 456, 102, 389, 147, 275` |
| **Pass 2** *(Size 2 → 4)* | `[125, 324]` & `[218, 456]`, `[102, 389]` & `[147, 275]` | `125, 218, 324, 456, 102, 147, 275, 389` |
| **Pass 3** *(Size 4 → 8)* | `[125, 218, 324, 456]` & `[102, 147, 275, 389]` | `102, 125, 147, 218, 275, 324, 389, 456` |

**Final Sorted Output:** `102, 125, 147, 218, 275, 324, 389, 456`

---

## Part B: Quick Sort Implementation & Execution

Quick Sort partitions the array around a chosen **pivot** element such that smaller values move to the left and larger values move to the right. The implementation below uses the **Lomuto partition scheme** (pivot selected as the last element).

### C Code Implementation (Abbreviated)

```c
void swap(int* a, int* b) { int t = *a; *a = *b; *b = t; }

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = (low - 1); 
  
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
```

### Execution Trace Table (Partition Results)

*Note: Bolded numbers indicate pivots placed into their final sorted positions.*

| Step | Pivot | Target Subarray Range | Array State After Partition |
| :--- | :--- | :--- | :--- |
| **Initial** | — | `[0 .. 7]` | `324, 125, 456, 218, 102, 389, 275, 147` |
| **Part 1** | 147 | `[0 .. 7]` | `125, 102, **147**, 218, 324, 389, 275, 456` |
| **Part 2** | 102 | `[0 .. 1]` | `**102**, 125, 147, 218, 324, 389, 275, 456` |
| **Part 3** | 456 | `[3 .. 7]` | `102, 125, 147, 218, 324, 389, 275, **456**` |
| **Part 4** | 275 | `[3 .. 6]` | `102, 125, 147, 218, **275**, 389, 324, 456` |
| **Part 5** | 324 | `[5 .. 6]` | `102, 125, 147, 218, 275, **324**, 389, 456` |

**Final Sorted Output:** `102, 125, 147, 218, 275, 324, 389, 456`

---

## Part C: Comparative Analysis

| Feature / Metric | Merge Sort | Quick Sort |
| :--- | :--- | :--- |
| **Passes / Partitions** | **7 Merge Steps** (structured across 3 recursion levels). | **5 Partitions** executed to place pivots in place. |
| **Comparisons / Operations** | ~17 comparisons ($N \log_2 N$ bound). High number of element copies to auxiliary memory buffers. | ~14 comparisons. Swaps are executed in-place inside the main array. |
| **Time Complexity** | **Best:** $O(N \log N)$<br>**Average:** $O(N \log N)$<br>**Worst:** $O(N \log N)$ | **Best:** $O(N \log N)$<br>**Average:** $O(N \log N)$<br>**Worst:** $O(N^2)$ |
| **Additional Space** | **$O(N)$ auxiliary space** required for temporary arrays during merge operations. | **$O(\log N)$ stack memory** space required for recursive function calls (In-place sorting). |
| **Algorithmic Stability** | **Stable** (Preserves relative order of duplicate keys). | **Unstable** (In-place element swapping can alter duplicate key ordering). |

---

## Complexity & Practical Suitability

### Why These Complexities Occur

1. **Merge Sort:** At each level, the array is divided strictly in half ($\log_2 N$ depth). Merging two sorted halves requires $N$ steps. Because splitting and merging happen unconditionally regardless of initial data order, performance is guaranteed to be $O(N \log N)$ in all cases.
2. **Quick Sort:** Performance depends heavily on pivot selection. In the average/best case, balanced partitions divide the problem into two equal subproblems, yielding $O(N \log N)$. However, if worst-case pivots are selected consistently (such as endpoint pivots on sorted/nearly sorted data), the recursion depth degrades to $O(N)$, resulting in $O(N^2)$ time.

---

## Final Analytical Conclusion

When selecting a sorting method for a large dataset of fixed-length social media user IDs:

1. **In-Memory Main RAM Processing (Quick Sort Recommended):**
   * **Quick Sort** is generally the superior choice for arrays stored in main memory due to its lower memory footprint ($O(\log N)$ stack space vs. $O(N)$ auxiliary buffer allocation for Merge Sort). It also exhibits better cache locality, resulting in faster real-world execution speeds.
   
2. **External Memory & Distributed Processing (Merge Sort Recommended):**
   * If the number of social media user IDs is so large that it exceeds RAM capacity (requiring disk or external database sorting), **Merge Sort** is strictly preferred. It accesses data sequentially rather than via random access swaps, making it the standard algorithm for external sorting pipelines.

**Final Recommendation:**
For standard in-memory operations on fixed-length IDs, **Quick Sort** (using randomized or median-of-three pivot selection) is recommended due to its $O(1)$ extra array memory requirement and fast practical runtime.