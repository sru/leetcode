# [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/)

## Test Cases

```
["flower","flow","flight"]
["flower", "flower", "flower"]
["flower", "flower", "flow"]
["", "flower", "flower", "flower", "flower"]
[""]
```

## [Loop Index](loop-index.c)

The solution's outer loop goes through the indices,
and its inner loop goes through the strings.
I think this probably is cache inefficient
because the strings may be in completely different addresses.

### Time Complexity

The time complexity of this solution is O(MN)
where M is the number of strings
and N is the minimum length of all strings.

### Spce Complexity

The solution does not use any additional space except the output.
So, the space complexity is O(1).
