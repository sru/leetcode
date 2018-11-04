# [Hamming Distance](https://leetcode.com/problems/hamming-distance/)

## [GCC Builtin Popcount](gcc-builtin-popcount.c)

Exclusive or (xor) produces 1 if two bits are different:

| a | b | a xor b |
|:-:|:-:|:-------:|
| 0 | 0 | 0       |
| 0 | 1 | 1       |
| 1 | 0 | 1       |
| 1 | 1 | 0       |

So, xoring two numbers produces a number with 1s only on bits that are different.

Using [Hamming Weight](https://en.wikipedia.org/wiki/Hamming_weight),
also called population count (popcount), on the result,
the number of different bits can be easily calculated.
Besides, GCC has a buitlin function for it, too.

### Time Complexity

O(1).

### Space Complexity

O(1).
