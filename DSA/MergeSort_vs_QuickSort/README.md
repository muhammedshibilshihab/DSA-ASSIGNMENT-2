# Merge Sort vs Quick Sort

## Student Details

Name: Muhammed Shibil Shihab
Department: Computer Science and Engineering with Business Systems (CEBS)
Roll No: VML25CEBS016

## Problem Statement

Social media platforms often need to sort large numbers of fixed-length
numeric IDs (for example, user IDs or post IDs) quickly and reliably.
This assignment compares two well-known sorting algorithms, **Merge
Sort** and **Quick Sort**, by implementing both in C, sorting the same
set of sample IDs, tracing their intermediate steps, and analyzing which
algorithm is better suited for sorting large, fixed-length keys.

## Given Input

324, 125, 456, 218, 102, 389, 275, 147

## Programs

### `src/merge_sort.c`

A simple recursive implementation of Merge Sort. It:
- Prints the original array.
- Prints every merge step (left part, right part, and the merged
  result).
- Prints the final sorted array.
- Prints the total number of merge operations and comparisons made.

### `src/quick_sort.c`

A simple recursive implementation of Quick Sort using the **Lomuto
partition scheme** (the last element of each part is used as the
pivot). It:
- Prints the original array.
- Prints every partition step (pivot value, each comparison made, and
  the array after that partition).
- Prints the final sorted array.
- Prints the total number of partitions and comparisons made.

## Execution

Both programs were compiled and actually run to produce their results.
The raw output is saved in:
- `output/merge_sort_output.txt`
- `output/quick_sort_output.txt`

Both programs correctly sort the input into:
`102 125 147 218 275 324 389 456`

## Trace Tables

- `trace/merge_sort_trace.txt` — step-by-step table of every merge
  operation (Left Part, Right Part, Merged Result).
- `trace/quick_sort_trace.txt` — step-by-step table of every partition
  operation (Pivot, Array/Partition Result, Important Comparisons).

## Analysis

- `analysis/comparison.md` — compares both algorithms on passes,
  comparisons, time complexity, space, working method, and suitability
  for large fixed-length keys.
- `analysis/complexity_analysis.md` — explains best, average, and worst
  case time complexity and additional space for both algorithms, and
  why each complexity occurs.

## Conclusion

`analysis/conclusion.md` gives the final verdict: for this small sample
input, both algorithms perform similarly, with Quick Sort using slightly
fewer comparisons in this run. However, for large-scale sorting of
fixed-length keys where predictable performance matters, **Merge Sort**
is the more reliable choice because it always guarantees `O(n log n)`
time, while Quick Sort can degrade to `O(n²)` in the worst case.

## How to Run

```bash
gcc src/merge_sort.c -o merge_sort
./merge_sort

gcc src/quick_sort.c -o quick_sort
./quick_sort
```

Both programs use the fixed input array built into the code (matching
`input/input.txt`), so no additional input needs to be typed in.

## Folder Structure

```text
MergeSort_vs_QuickSort/
│
├── README.md
│
├── src/
│   ├── merge_sort.c
│   └── quick_sort.c
│
├── input/
│   └── input.txt
│
├── output/
│   ├── merge_sort_output.txt
│   └── quick_sort_output.txt
│
├── trace/
│   ├── merge_sort_trace.txt
│   └── quick_sort_trace.txt
│
├── analysis/
│   ├── comparison.md
│   ├── complexity_analysis.md
│   └── conclusion.md
│
└── docs/
    └── assignment_requirements.md
```
