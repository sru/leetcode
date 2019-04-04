# [Broken Calculator](https://leetcode.com/problems/broken-calculator/)

## [Working Backward](working-backward.c)

Intuitively, it's easier to reason about this problem by working backward from `Y` to `X`.
If `Y` is smaller than `X`,
the only choice is to decrement `X - Y` times.
Otherwise, I can consider 2 cases.

For any (intermediate or final) value of `Y`,
the only way that it become odd is to decrement from the previous `Y` value.
If it is even, it must've been doubled from the previous `Y` value
because it's the fastest way.

### Time Complexity

The time complexity of this algorithm depends on the values of the numbers.
It's O(max(X, Y)).

### Space Complexity

There is no additional space required that depends on input size,
so the space complexity is O(1).
