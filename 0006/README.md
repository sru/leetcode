# [ZigZag Conversion](https://leetcode.com/problems/zigzag-conversion/)

## [Derive Original Index](derive-original-index.c)

This solution calculates the index on the original string depending on the position in the row.
The zigzag pattern makes "N" reversed shape.
The same position in the reversed "N" is always `2 * (numRows - 1)` apart from each other.
Besides the first and the last row,
each row has exactly 1 middle position to fill,
which is row number subtracted from the index of the beginning of the reversed "N".

### Time Complexity

The solution goes through each character once.
O(N) where `N` is the number of characters in the string.

### Space Complexity

Since this solution is not in-place replacement,
the space complexity is O(N),
where `N` is the number of characters in the string.
