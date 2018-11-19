#[Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)

## Test Cases

```
""
"23"
"78"
"97"
"37"
```

## [Derive Character from Index](derive-character-from-index.c)

This solution derives characters of current combination from the index.
It can generate answer in lexicographical order
if the number of possible combinations is calculated from the back to front.

### Time Complexity

O(N * (4^N)) where N is the number of characters in the input.
The solution must fill out at maximum 4^N possible combinations
in which each combination is length of N.
So this is the most time-efficient.

### Space Complexity

O(N) where N is the number of characters in the input,
excluding the space required for the output.
The solution stores the intermediate result of number of possible combinations.
