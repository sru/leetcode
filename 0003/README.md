# [Longest Substring without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

## Test Cases

```
"pwwkew"
"asdf"
"asddsab"
"bbbbb"
"abcabcbb"
"a"
""
```

## [Hash Table](hash-table.c)

The solution uses hash table to store the previously known character index.
Since I am finding the longest substring, I can go through each index
and store the character's index and the number of unique characters.
If I encounter a previously encountered character,
I check if that character is inside the substring
and move the start of the substring to 1 after that character
to exclude the character.
Then, I just need to keep track of the maximum length of the substring.

### Time Complexity

The time complexity of this solution is O(N^2) in the worst case
and O(N) in the average case,
assuming hash table performs in O(N) in the worst case
and O(1) in the average case,
where N is the number of characters inside the string.
It is because the solution goes through each character exactly once.

### Space Complexity

Since I may store in hash table up to N values,
where N is the number of characters inside the string,
this solution has space complexity of O(N).

## [Array](array.c)

This solution is similar to hash table one, except it uses array.
Since the number of possible character is so small,
we can just use array rather than hash table.

### Time Complexity

The time complexity of this solution is O(N),
where N is the number of characters in the input string,
because the solution goes through each character exactly once.

### Space Complexity

This solution has space complexity of O(1)
because it does need any additional memory that depends on input size.
