/**
 * # Problem
 *
 * Given a string __s__, find the longest palindromic substring in __s__. You
 * may assume that the maximum length of __s__ is 1000.
 *
 * # Test Cases
 *
 * - "babad"
 * - "cbbd"
 * - "a"
 * - ""
 * - "abbba"
 * - "abbbba"
 * - "abbcbbadabbcbbaabbcbba"
 * - "xabbccbbbad"
 * - "abbabba"
 * - "cabbaccabba"
 * - "babcbabc"
 *
 * # Solution
 *
 * This solution finds the center and expand the center if the surround
 * characters are the same.
 *
 * ## Time Complexity
 *
 * The solution may go through the whole string per each character in the string
 * to find the surrounding characters. So, the time complexity is O(N^2), where
 * `N` is the number of characters in the string.
 *
 * ## Space Complexity
 *
 * There are no additional space needed that depends on the input size. So the
 * space complexity is O(1).
 */

char* longestPalindrome(char* s) {

    // Sanity checks.
    if (s == NULL || s[0] == '\0' || s[1] == '\0') {
        return s;
    }

    int best_start = 0;
    int best_end = 1;
    int center = 0;

    while (s[center] != '\0') {

        // Find the largest center.
        int center2 = center + 1;
        for (char ch = s[center]; s[center2] == ch; ++center2);

        // Find the surrounding characters.
        int start = center;
        int end = center2;
        while (start > 0 && s[start - 1] == s[end]) {
            --start;
            ++end;
        }

        // Update the best.
        if (best_end - best_start < end - start) {
            best_start = start;
            best_end = end;
        }

        // Next center.
        center = center2;
    }

    // Modify string to match the answer.
    s[best_end] = '\0';
    return &s[best_start];
}
