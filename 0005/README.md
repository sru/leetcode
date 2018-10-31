# [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)

## Test Cases

```
"babad"
"cbbd"
"a"
""
"abbba"
"abbbba"
"abbcbbadabbcbbaabbcbba"
"xabbccbbbad"
"abbabba"
"cabbaccabba"
"babcbabc"
```

## [Find Center and Expand](find-center-and-expand.c)

This solution finds the center and expand the center
if the surround characters are the same.

### Time Complexity

The solution may go through the whole string per each character in the string
to find the surrounding characters.
So, the time complexity is O(N^2),
where `N` is the number of characters in the string.

### Space Complexity

There are no additional space needed that depends on the input size.
So the space complexity is O(1).
