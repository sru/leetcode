# [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/)

## [List Traversal](traverse-lists.c)

Since the digits are stored in reverse order,
we can go through each digits and add them together,
along with proper carry, to achieve addition on the linked lists.
The first loop goes through every digit pair on both `l1` and `l2`.
The second loop goes through every digits existing in one list
but not in the other.
For such digits, we only care about digit places affected by the carry;
the rest remain as they are.

### Time Complexity

Let `N` be the number of digits of the first integer
and `M` the number of digits of the second integer.
The solution has time complexity of O(max(N, M)).

### Space Complexity

There is no additional space used that depends on input,
so the solution has constant space complexity (O(1)).
