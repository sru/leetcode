# [Regular Expression Matching](https://leetcode.com/problems/regular-expression-matching/)

## Test Cases

```
"aa"
"a"
"aa"
"a*"
"ab"
".*"
"aab"
"c*a*b"
"mississippi"
"mis*is*p*."
"aaaba"
"a*"
```

## [Dynamic Programming](dynamic-programming.c)

The solution uses extra space to memoize whether a prefix of the string matches a prefix of the pattern,
starting from the empty string and the empty pattern.

To match the emtpy string,
all literals (and dots) in the pattern must be followed by star to match exactly zero elements of everything.
When current pattern character in pattern is a star,
if the pattern prefix excluding the star and previous pattern character matches,
then current pattern prefix matches as well
because the star can match zero elements of previous pattern character.

For any literal or dot in the pattern,
check if the previous string prefix matches the previous pattern prefix.
Then, check if the current pattern character is a dot,
which unconditionally matches any character in the string,
or if it matches the current string character.

For any star in the pattern,
check if the previous string prefix matches the current pattern prefix.
Then, match the previous pattern character and the current string character
because star allows zero or more of previous pattern character.

After going through every pattern character and string character,
the last place should contain result whether the whole pattern and string matches.

### Time Complexity

The solution finds the answer by filling up `(M + 1) * (N + 1)` matrix,
where `M` and `N` are input sizes of the string and the pattern, respectively,
so the time complexity is O(MN).

### Space Complexity

The solution uses `(M + 1) * (N + 1)` extra space,
where `M` and `N` are input sizes of the string and the pattern, respectively,
so, the space complexity is O(MN).
