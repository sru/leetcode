# [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)

## Test Cases

```
""
"()"
"()[]{}"
"(]"
"([)]"
"{[]}"
```

## [Stack](stack.c)

This solution uses stack to keep track of open brackets.
Since open brackets must be closed in the correct order,
matching open bracket must be at the top of the stack for any close bracket.
By the end of the string, the stack must be empty
because all open brackets must be closed by same type of brackets.

### Time Complexity

O(N), where N is the number of characters.

### Space Complexity

O(N), where N is the number of characters.
