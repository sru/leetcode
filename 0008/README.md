# [String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi/)

## Test Cases

```
"42"
"-42"
"4193 with words"
"words and 987"
"-91283472332"
"+1"
```

## [GCC builtin](gcc-builtin.c)

The solution is straightforward.
The solution uses gcc's builtin extension for detecting overflow on operations.

## Time Complexity

Since the solution goes through each character once,
the solution has time complexity of O(N),
where N is the number of characters in the string.

## Space Complexity

The solution has space complexity of O(1)
because it does not use extra spaces that depend on input size.
