# [Ugly Number](https://leetcode.com/problems/ugly-number/)

## Test Cases

```
6
14
30
-1
0
```

## [Keep Dividing](keep-dividing.c)

The solution divides the input by 2, 3, and 5
until no factor of 2, 3, or 5 is left in the input.
If the input's prime factors only include 2, 3, and 5,
the leftover should be 1 because all factors should have been divided out.

### Time Complexity

I am unsure about how to reason about time complexity of this solution.
I believe it is O(log(N)) where N is the input
because the number of divisions depends on how many factors of 2, 3, and 5 the input has.

### Space Complexity

Because no storage is required that depends on the size of the input,
the space complexity is O(1).
