# [Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/)

## Test Cases

```
[1, 2]
[1, 2, 2, 1]
[1, 2, 3, 2, 1]
[1, 2, 2, 2, 1]
[1]
[]
```

## [Reverse Half](reverse-half.c)

This solution reverses half of the singly linked list, and compares them.
It finds the half point by using two pointers,
`tail` that skips 2 at a time
and `half` that skips only 1 at a time.
`tail` pointer is modified to truly point to the tail of the linked list to use later.
If there are even numbers of elements,
`half` pointer points to the element right before the middle.
Otherwise, it points to the lement right in the middle.
`half` pointer is advanced once
to point to latter half of the list.
Then, the list from `half` to `tail` is reversed,
and compared element by element from `head` and `tail` pointers.

### Time Complexity

O(N), where N is the number of elements in the singly linked list.

### Space Complexity

O(1) because there are no additional space used
although the solution modifies the original list.
