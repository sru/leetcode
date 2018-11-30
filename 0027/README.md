# [Remove Element](https://leetcode.com/problems/remove-element/)

## [Two Indices](two-indices.c)

This solution uses 2 indicies into the array:
The current element and the next empty slot in the "new" array.
The index for the current element is always greater or equal to the index for the next empty slot.
So, every element that is overwritten has already been visited.

### Time Complexity

O(N) where N is the number of elements.

### Space Complexity

O(1).
