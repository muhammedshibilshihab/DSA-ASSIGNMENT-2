# Conclusion

## Based on Actual Execution (This Assignment's Input)

For the given 8 social media IDs (`324, 125, 456, 218, 102, 389, 275,
147`), both `merge_sort.c` and `quick_sort.c` correctly produced the same
final sorted array:

```
102 125 147 218 275 324 389 456
```

- **Merge Sort** took **7 merge operations** and **17 comparisons**.
- **Quick Sort** took **5 partition operations** and **16 comparisons**.

For this small, non-adversarial input, Quick Sort used slightly fewer
comparisons and fewer high-level steps than Merge Sort, and it did all
its work directly inside the original array (in place), while Merge
Sort needed extra temporary arrays at every merge step.

## Based on Trace Tables

The trace tables (`trace/merge_sort_trace.txt` and
`trace/quick_sort_trace.txt`) show that Merge Sort's steps are very
regular and predictable — it always splits down to single elements and
merges back up, regardless of the input values. Quick Sort's steps,
however, depend heavily on where the pivot lands after each partition;
in this run, the pivots happened to split the array reasonably well,
which kept the partition count low.

## Based on Complexity and Space

Theoretically:

- Merge Sort **always** runs in `O(n log n)` time, no matter the input,
  but always uses `O(n)` extra memory for merging.
- Quick Sort **usually** runs in `O(n log n)` time and uses very little
  extra memory (`O(log n)` typically), but it can degrade to `O(n²)` in
  the worst case — for example, on data that is already sorted or
  reverse-sorted, when a poor pivot (like the last element) is always
  chosen.

## Small Input vs Larger Input: An Important Distinction

For a **small input like this 8-element example**, the difference
between the two algorithms is minor — both run almost instantly, and the
small gap in comparisons (16 vs 17) is not meaningful in practice.

For **large collections of fixed-length keys** (such as millions of real
social media IDs on a production server), the picture theoretically
changes:

- If the incoming data could sometimes be **already sorted or nearly
  sorted** (a realistic possibility, e.g., IDs assigned sequentially),
  Quick Sort's worst-case `O(n²)` becomes a real risk unless a safer
  pivot strategy (random pivot or median-of-three) is used.
- **Merge Sort's guaranteed `O(n log n)` performance** makes it the
  safer and more predictable choice for large-scale, reliability-critical
  sorting, at the cost of extra memory.
- **Quick Sort remains attractive** when memory is limited and the data
  is not likely to be adversarial, since it sorts in place and is often
  faster in practice due to lower constant factors and better cache
  behavior.

## Final Verdict

For **this small assignment input**, Quick Sort performed marginally
more efficiently (fewer comparisons, in-place sorting), but the
difference is too small to be significant.

For **large-scale sorting of fixed-length keys** where consistent,
predictable performance matters more than raw average speed — such as
backend systems sorting large batches of social media IDs — **Merge
Sort is the more suitable and reliable choice**, because it guarantees
`O(n log n)` performance in every case, while Quick Sort's worst-case
`O(n²)` behavior can appear unexpectedly on certain input patterns.
