# [Integer to Roman](https://leetcode.com/problems/integer-to-roman/)

## Test Cases

```
3
3999
3888
```

## [Switch Macro](switch-macro.c)

The solution is straightforward.
I used macro because I don't like repeating things.
It could be generalized with loops to accomodate more Roman numerals.

### Time Complexity

Since the input and the output are bounded by number of Roman numerals,
it's a silly to talk about asymptotic behavior.
If there were unlimited number of Roman numerals,
the time complexity of this solution would be O(N)
where N is the number of digits of the input.

### Space Complexity

Since the input and the output are bounded by number of Roman numerals,
it's a silly to talk about asymptotic behavior.
Even if there were unlimited number of Roman numerals,
the space complexity of this solution would be O(1)
because no additional space, except the output, depends on the size of the input.
