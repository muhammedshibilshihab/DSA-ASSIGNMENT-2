# Complexity Analysis

## Merge Sort

| Case | Complexity | Why |
|---|---|---|
| Best Case | O(n log n) | Merge Sort always splits the array in half and merges, no matter how the input is arranged. There is no "lucky" arrangement that skips work. |
| Average Case | O(n log n) | On average, the array is split into `log n` levels, and each level requires `n` comparisons to merge everything back together, giving `n log n` total work. |
| Worst Case | O(n log n) | Even in the worst possible input order, the splitting pattern and merge work stay exactly the same. Merge Sort has no input-dependent slowdown. |
| Additional Space | O(n) | Merging requires temporary arrays (`leftArr` and `rightArr` in the program) to hold the two halves while they are combined back into the original array. |

**Why the complexity occurs:** Merge Sort always divides the array into
two equal halves (this takes `log n` levels of splitting for `n`
elements), and merging all elements back together at each level takes
`O(n)` work. Multiplying the number of levels by the work per level
gives `O(n log n)`. This pattern never changes, which is why Merge
Sort's best, average, and worst cases are all the same.

## Quick Sort

| Case | Complexity | Why |
|---|---|---|
| Best Case | O(n log n) | Happens when the pivot chosen at each step splits the array into two roughly equal halves, similar to Merge Sort's balanced splitting. |
| Average Case | O(n log n) | For most random input orders, pivots tend to split the array reasonably well on average, giving `n log n` behavior overall. |
| Worst Case | O(n²) | Happens when the pivot is repeatedly the smallest or largest element (for example, an already-sorted array with "last element as pivot"). Each partition then only removes one element, requiring `n` partitions of decreasing size (`n + (n-1) + (n-2) + ... + 1`), which adds up to `O(n²)`. |
| Additional Space | O(log n) average, O(n) worst case | Quick Sort sorts the array **in place** using swaps, so it does not need extra arrays like Merge Sort. The only extra space is the recursion call stack, which is `O(log n)` deep when partitions are balanced, but can grow to `O(n)` deep in the worst case (very unbalanced partitions). |

**Why the complexity occurs:** Quick Sort's performance depends entirely
on how balanced each partition is. A good pivot removes roughly half the
remaining elements each time, leading to `log n` levels of partitioning
(same shape as Merge Sort) at `O(n)` work per level, giving `O(n log
n)`. A poor pivot removes only one element at a time, leading to `n`
levels instead of `log n`, which is what causes the `O(n²)` worst case.

## Quick Summary

| | Merge Sort | Quick Sort |
|---|---|---|
| Guaranteed speed | Yes, always O(n log n) | No, can degrade to O(n²) |
| Memory usage | Higher (O(n) extra) | Lower (in-place, O(log n) typical) |
| Depends on input order | No | Yes |
| Depends on pivot choice | Not applicable | Yes |
