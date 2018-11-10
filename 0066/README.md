# [Plus One](https://leetcode.com/problems/plus-one/)

## Test Cases

```
[1,2,3]
[9, 9, 9, 8]
[9, 9, 9, 9]
```

## [Reverse Traversal](reverse-traversal.c)

The solution traverses from the end adding the carry if needed.
Carry is initially set to 1 because 1 is added to the whole number.
When carry is 1 after looping through all indices,
new digit place is needed.

### Time Complexity

O(N), where N is the number of digits.
At worst case, where every digit is 9,
the solution goes through every digit, adding carry to each one of them.

### Space Complexity

O(1). There is no additional space needed besides the output.
