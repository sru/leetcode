# [Convert a Number to Hexadecimal](https://leetcode.com/problems/convert-a-number-to-hexadecimal/)

## Test Cases

```
26
-1
0
65535
65536
65538
65552
```

## [Switch Table](switch-table.c)

The solution converts 4 bits at a time using switch statement.
It finds the first 4 most signitifcant bits that have value
in order to not prepend the result with leading 0s.

### Time Complexity

O(1).

### Space Complexity

O(1).
