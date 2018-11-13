# [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)

## Test Cases

```
[1, 2, 4]
[1, 3, 4]
[1, 2, 3]
[4, 5, 6]
[4, 5, 6]
[1, 2, 3]
[1, 3, 5]
[2, 4, 6]
[1, 2, 5, 6]
[3, 4, 7, 7]
```

## [Rearrange](rearrange.c)

The solution rearranges pointers inside both lists to create the merged list.
It compares the head of both lists.
The head with smaller value is assigned as next element,
The list is skipped until the value is no longer smaller or equal to that of the other head
because those elements do not need to be rearranged.
Then, the other head is assigned as next element and the list skipped in similar manner.
This is repeated until one of the lists is empty.
Then, the non-empty list is tagged on at the end.

### Time Complexity

O(N), where N is the total number of elements in both lists.

### Space Complexity

O(1); the solution only reaaranges some pointers.
