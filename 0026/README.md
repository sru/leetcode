# [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)

## [Two Indices](two-indices.c)

This solution keeps track of two indices,
one that goes through the elements in the array,
the other that keeps track of next overwrite place.
Since the former will always be equal or greater than the latter,
the overwritten elements are already searched and are not needed any more.

### Time Complexity

O(N) where N is the number of elements in the array.

### Space Complexity

O(1).
