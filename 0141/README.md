# [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle)

## [Fast and Slow](fast-and-slow.c)

This solution uses two pointers,
one that goes one at a time
and the other that goes two at a time.
When any pointer reaches the end of the linked list,
I know for sure that linked list does not have cycle.
If it has cycle, then two pointers will eventually point to the same element
because they go in different speed.

### Time Complexity

O(N) where N is the number of elements in the linked list.

### Space Complexity

O(1).
