# [Container with Most Water](https://leetcode.com/problems/container-with-most-water/)

## [Toward Middle](toward-middle.c)

This solution starts from the two ends and work toward the middle.
The index to progress toward the middle is selected by choosing the index with shorter height
because the area is determined by shortest side;
I want to see whether there is better side to choose.
By doing so, I establish an invariant that, for any left and right indices,
the maximum area so far is the maximum area of containers wider than current width.

### Time Complexity

The time complexity of the solution is O(n)
because it traverses the input list at most once.

### Space Complexity

The space complexity of the solution is O(1)
because the additional space does not depend on input size.
