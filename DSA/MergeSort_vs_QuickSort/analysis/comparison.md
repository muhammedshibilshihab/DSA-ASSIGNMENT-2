# Comparison: Merge Sort vs Quick Sort

Input used: `324, 125, 456, 218, 102, 389, 275, 147` (8 social media IDs)

All numbers below for **this specific input** are taken directly from the
verified execution of `merge_sort.c` and `quick_sort.c`
(see `output/merge_sort_output.txt` and `output/quick_sort_output.txt`).
They are not estimated — they are the exact counters printed by the
programs themselves.

## Comparison Table

| Criteria | Merge Sort | Quick Sort |
|---|---|---|
| Passes / partitions (this run) | 7 merge operations | 5 partition operations |
| Comparisons made (this run) | 17 comparisons | 16 comparisons |
| Time Complexity (Best) | O(n log n) | O(n log n) |
| Time Complexity (Average) | O(n log n) | O(n log n) |
| Time Complexity (Worst) | O(n log n) | O(n²) |
| Additional Space | O(n) — needs temporary arrays for merging | O(log n) — only recursion stack (sorts in place) |
| Working Method | Divide the array, sort each half recursively, then **merge** the sorted halves | Pick a **pivot**, partition the array around it, then recursively sort each side |
| Stability | Stable (equal elements keep their relative order) | Not stable (swaps can reorder equal elements) |
| Suitability for large fixed-length keys | Very reliable — performance never degrades regardless of input order | Usually faster in practice, but can degrade to O(n²) on already-sorted or specially-crafted input |

## Notes on the Numbers Above

- **Passes/partitions**: For 8 elements, Merge Sort always performs
  exactly 7 merge operations (this is fixed by the divide-and-conquer
  structure and does not depend on the input order). Quick Sort's number
  of partitions **does** depend on the input order and the pivot choice;
  for this particular input using a "last element as pivot" strategy, it
  took 5 partitions.
- **Comparisons**: Merge Sort made 17 comparisons and Quick Sort made 16
  comparisons for this specific input and this specific pivot strategy.
  These counts would change if the input order changed or if a different
  pivot rule (e.g., first element, middle element, random, or
  median-of-three) were used for Quick Sort. This is expected — Quick
  Sort's comparison count is input-dependent, while Merge Sort's is
  almost fixed for a given array size.
- Because the counts above depend on implementation details (pivot
  choice, partition scheme), they should be read as results for **this
  program and this input**, not as universal constants for either
  algorithm.

## Working Method (Short Explanation)

**Merge Sort** keeps splitting the array into two halves until each part
has only one element, then merges pairs of sorted parts back together in
order. It always looks at every element in a structured, predictable
way, which is why its performance is so consistent.

**Quick Sort** picks one element (the pivot) and rearranges the array so
that smaller elements go to its left and larger elements go to its
right. It then repeats this process on each side. Its speed depends
heavily on how "balanced" the partitions turn out to be, which in turn
depends on the pivot chosen and the original order of the data.

## Suitability for Large Fixed-Length Keys

Social media IDs are typically **fixed-length numeric keys** (similar to
the 3-digit IDs used here, just longer in a real system). For such data:

- **Merge Sort** is the safer choice when consistent, predictable
  performance matters (e.g., sorting large batches of IDs on a server
  where worst-case behavior must be avoided), at the cost of extra
  memory.
- **Quick Sort** is usually faster in practice and uses very little
  extra memory, making it attractive when memory is limited and the
  input is not adversarial or already sorted.

See `complexity_analysis.md` and `conclusion.md` for a deeper discussion.
