# [Palindrome Number](https://leetcode.com/problems/palindrome-number/)

## Test Cases

```
121
-121
10
```

## [Reverse Half](reverse-half.c)

The solution "reverses" half of the digits of x, and compare the result.
Since `x` and `i` are integers and I am only adding up half of the digits,
it will never overflow.

### Time Complexity

The solution traverses through half of the digits,
so it has time complexity of O(log10(x)).

### Space Complexity

The solution does not have any space that depends on input size,
so it has space complexity of O(1).
