/**
 * # Problem
 *
 * Given a string, find the length of the __longest substring__ without
 * repeating characters.
 *
 * # Solution
 *
 * This solution is similar to hash table one, except it uses array. Since the
 * number of possible character is so small, we can just use array rather than
 * hash table.
 *
 * ## Time Complexity
 *
 * The time complexity of this solution is O(N), where N is the number of
 * characters in the input string, because the solution goes through each
 * character exactly once.
 *
 * ## Space Complexity
 *
 * This solution has space complexity of O(1) because it does need any
 * additional memory that depends on input size.
 *
 * # Custom Test Cases
 *
 * ```
 * "pwwkew"
 * "asdf"
 * "asddsab"
 * "bbbbb"
 * "abcabcbb"
 * "a"
 * ""
 * ```
 */

int lengthOfLongestSubstring(char* s) {
    int indices[256];
    int len_max = 0;
    int start = 0;

    for (int i = 0; i < 256; ++i) {
        indices[i] = -1;
    }

    for (int i = 0; s[i] != '\0'; ++i) {

        if (indices[s[i]] >= start) {
            start = indices[s[i]] + 1;
        }

        indices[s[i]] = i;

        if (len_max < i - start + 1) {
            len_max = i - start + 1;
        }
    }

    return len_max;
}
