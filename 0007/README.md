# [Reverse Integer](https://leetcode.com/problems/reverse-integer/)

## Test Cases

```
123
-123
120
```

## [GCC builtin](gcc-builtin.c)

The solution goes through every digit started from the least significant one,
and append them to the result using gcc's builtin overflow checking operations.

### Time Complexity

The time complexity of this solution is O(log10(x)), where x is the input.

### Space Complexity

The solution uses only constant extra space,
so this solution has space complexity of O(1).
