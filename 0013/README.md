# [Roman to Integer](https://leetcode.com/problems/roman-to-integer/)

## Test Cases

```
"III"
"IV"
"LVIII"
"MCMXCIV"
"MMMCDLXXXIV"
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
where N is the number of Roman numerals of the input.

### Space Complexity

Since the input and the output are bounded by number of Roman numerals,
it's a silly to talk about asymptotic behavior.
Even if there were unlimited number of Roman numerals,
the space complexity of this solution would be O(1)
because no additional space depends on the size of the input.
