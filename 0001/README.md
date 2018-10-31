# [Two Sum](https://leetcode.com/problems/two-sum/)

## [Nested Loop](nested-loop.c)

This is a straightforward solution with nested loop.
The outer loop finds the first index,
and the inner loop finds the second index.

### Time Complexity

Since there are `N choose 2`, `N * (N - 1) / 2`, combinations of indices,
the time complexity is O(N^2), where `N` is the number of elements.

### Space Complexity

There is no additional space required that depends on input size,
so the space complexity is O(1).

## [Hash Table](hash-table.c)

This solution uses hash table, from uthash,
which is already included in LeetCode.
`Entry` is defined to make the hash table mimic a hash map.
The map stores the number as key and the index as value.
If I can find `target - nums[i]` in the hash table,
the number has already been seen,
so I can just return the number's index and the current index.

### Time Complexity

Let `N` denote the number of elements.

The solution goes through the elements once.
Since look up and add operations of hash table is normally constant-time,
the solution has the average time complexity of O(N).
The worst time complexity depends on the hash table implementation.
Assuming the hash table operations are worst-case O(N),
the solution has the worst time complexity of O(N^2).

### Space Complexity

This solution allocates `N` entries for the map upfront.
I could allocate on the fly,
but it would complicate keeping track of the entries to free.
Also, I think allocating huge chunk of entries is better for cache locality.
The map will have at most `N` entries.
The solution has the space complexity of O(N).
