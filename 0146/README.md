# [LRU Cache](https://leetcode.com/problems/lru-cache/)

## Test Cases

```
["LRUCache","put","put","get","put","get","put","get","get","get"]
[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]
["LRUCache","put","put","put","put","get","get"]
[[2],[2,1],[1,1],[2,3],[4,1],[1],[2]]
```

## [Hash Table and Linked List](hash-table-and-linked-list.c)

The solution employs hash table for faster look up
and doubly-linked list for bookkeeping least recently used element.
Most recently used element is put at the head of the list,
so the tail of the list naturally becomes least used element.
When capacity is full,
the tail of the list is replaced with new key and value.

### Time Complexity

Time complexity is the time complexity of a hash table.

O(1) for both operations in average case,
and O(N) in worst case, where N is the capacity.

### Space Complexity

O(N) where N is the capacity.
